// docker/devices/pv/ied/ied_server.c

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <math.h>

#include "iec61850_server.h"
#include "iec61850_common.h"

#include "hal_time.h"
#include "mms_value.h"

#include "static_model.h"
#include "device_map.h"

#include "process_image.h"
#include "printmap.h"   /* read_point_double/read_coil01/write_coil01/write_point_double */

static void iec_print_state(IedServer srv)
{
    if (!srv) return;

    /* print once every 2 seconds */
    static uint64_t last_ms = 0;
    uint64_t now = Hal_getTimeInMs();
    if (now - last_ms < 2000)
        return;
    last_ms = now;

    printf("\n=== IEC STATE (from IED model, not Modbus) ===\n");

    /* ---- MX: AnIn1..AnIn5.mag.f ---- */
    struct {
        const char* name;
        DataAttribute* mag_f;
    } anin[] = {
        { "GGIO1.AnIn1.mag.f (P.P_PV)",      IEDMODEL_PVLD0_GGIO1_AnIn1_mag_f },
        { "GGIO1.AnIn2.mag.f (P.V_PV)",   IEDMODEL_PVLD0_GGIO1_AnIn2_mag_f },
        { "GGIO1.AnIn3.mag.f (P.I_PV)",   IEDMODEL_PVLD0_GGIO1_AnIn3_mag_f },
        { "GGIO1.AnIn4.mag.f (PV.DutyCycle)",   IEDMODEL_PVLD0_GGIO1_AnIn4_mag_f },
        { "GGIO1.AnIn5.mag.f (PV.Irradiance)",     IEDMODEL_PVLD0_GGIO1_AnIn5_mag_f },

    };

    for (unsigned i = 0; i < (unsigned)(sizeof(anin)/sizeof(anin[0])); i++) {
        float v = IedServer_getFloatAttributeValue(srv, anin[i].mag_f);
        printf("[MX] %-28s = %.6f\n", anin[i].name, (double)v);
    }

    /* ---- SP: DO1..DO4.setMag.f ---- */
    for (int i = 0; i < PV_SETPOINT_MAP_COUNT; i++) {
        if (!PV_SETPOINT_MAP[i].mag_f) continue;
        float v = IedServer_getFloatAttributeValue(srv, PV_SETPOINT_MAP[i].mag_f);
        printf("[SP] %-28s = %.6f  (-> %s)\n",
               (PV_SETPOINT_MAP[i].modbus_name ? PV_SETPOINT_MAP[i].modbus_name : "setpoint"),
               (double)v,
               PV_SETPOINT_MAP[i].modbus_name ? PV_SETPOINT_MAP[i].modbus_name : "(null)");
    }

    /* ---- CO status: CBPV.stVal ---- */
    if (PV_CBPV_STVAL) {
        MmsValue* mv = IedServer_getAttributeValue(srv, PV_CBPV_STVAL);
        if (mv && MmsValue_getType(mv) == MMS_BOOLEAN) {
            bool b = MmsValue_getBoolean(mv);
            printf("[CO] GGIO1.SPCSO1.stVal (CBPV) = %d\n", b ? 1 : 0);
        } else if (mv) {
            printf("[CO] GGIO1.SPCSO1.stVal (CBPV) type=%d\n", (int)MmsValue_getType(mv));
        } else {
            printf("[CO] GGIO1.SPCSO1.stVal (CBPV) = (null)\n");
        }
    }

    if (PV_CBPV_CTLMODEL) {
        int32_t cm = IedServer_getInt32AttributeValue(srv, PV_CBPV_CTLMODEL);
        printf("[CF] GGIO1.SPCSO1.ctlModel = %d\n", (int)cm);
    }

        /* ---- CO status: CurtailEnable.stVal ---- */
    if (PV_CurtailEnable_STVAL) {
        MmsValue* mv = IedServer_getAttributeValue(srv, PV_CurtailEnable_STVAL);
        if (mv && MmsValue_getType(mv) == MMS_BOOLEAN) {
            bool b = MmsValue_getBoolean(mv);
            printf("[CO] GGIO1.SPCSO2.stVal (CurtailEnable) = %d\n", b ? 1 : 0);
        } else if (mv) {
            printf("[CO] GGIO1.SPCSO2.stVal (CurtailEnable) type=%d\n", (int)MmsValue_getType(mv));
        } else {
            printf("[CO] GGIO1.SPCSO2.stVal (CurtailEnable) = (null)\n");
        }
    }

    if (PV_CurtailEnable_CTLMODEL) {
        int32_t cm = IedServer_getInt32AttributeValue(srv, PV_CurtailEnable_CTLMODEL);
        printf("[CF] GGIO1.SPCSO2.ctlModel = %d\n", (int)cm);
    }

    printf("=============================================\n");
}


typedef struct {
    IedServer srv;
    process_image_t* pi;
} control_ctx_t;

static control_ctx_t g_ctl = {0};
static volatile int running = 0;

static void sigint_handler(int sig)
{
    (void)sig;
    running = 0;
}

static void connectionHandler(IedServer self, ClientConnection connection, bool connected, void* parameter)
{
    (void) self;
    (void) parameter;

    const char* ip = connection ? ClientConnection_getPeerAddress(connection) : NULL;

    if (connected)
        printf("[IEC] Connection opened (%s)\n", ip ? ip : "unknown");
    else
        printf("[IEC] Connection closed (%s)\n", ip ? ip : "unknown");
}

/* Control handler: CBPV (SPCS01) -> Modbus coil */
static ControlHandlerResult
cbpv_control_handler(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    (void) action;

    control_ctx_t* ctx = (control_ctx_t*) parameter;

    if (!ctx || !ctx->srv || !ctx->pi)
        return CONTROL_RESULT_FAILED;

    if (test) {
        printf("[IEC][CTL] CBPV TEST -> rejected\n");
        return CONTROL_RESULT_FAILED;
    }

    if (!value || MmsValue_getType(value) != MMS_BOOLEAN) {
        printf("[IEC][CTL] CBPV invalid type (expect BOOLEAN)\n");
        return CONTROL_RESULT_FAILED;
    }

    bool on = MmsValue_getBoolean(value);
    int coil01 = on ? 1 : 0;

    pi_lock(ctx->pi);
    int rc = write_coil01(ctx->pi, PV_CBPV_COIL_NAME, coil01);
    pi_unlock(ctx->pi);

    if (rc != 0) {
        printf("[IEC][CTL] write_coil01(%s) failed rc=%d\n", PV_CBPV_COIL_NAME, rc);
        return CONTROL_RESULT_FAILED;
    }

    uint64_t ts = Hal_getTimeInMs();

    if (PV_CBPV_T)
        IedServer_updateUTCTimeAttributeValue(ctx->srv, PV_CBPV_T, ts);

    if (PV_CBPV_STVAL)
        IedServer_updateAttributeValue(ctx->srv, PV_CBPV_STVAL, value);

    printf("[IEC][CTL] CBPV SUCCESS: coil=%d\n", coil01);

    return CONTROL_RESULT_OK;
}

/* Control handler: CURTAILENABLE (SPCS01) -> Modbus coil */
static ControlHandlerResult
curtailenable_control_handler(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    (void) action;

    control_ctx_t* ctx = (control_ctx_t*) parameter;

    if (!ctx || !ctx->srv || !ctx->pi)
        return CONTROL_RESULT_FAILED;

    if (test) {
        printf("[IEC][CTL] CURTAILENABLE TEST -> rejected\n");
        return CONTROL_RESULT_FAILED;
    }

    if (!value || MmsValue_getType(value) != MMS_BOOLEAN) {
        printf("[IEC][CTL] CURTAILENABLE invalid type (expect BOOLEAN)\n");
        return CONTROL_RESULT_FAILED;
    }

    bool on = MmsValue_getBoolean(value);
    int coil01 = on ? 1 : 0;

    pi_lock(ctx->pi);
    int rc = write_coil01(ctx->pi, PV_CurtailEnable_COIL_NAME, coil01);
    pi_unlock(ctx->pi);

    if (rc != 0) {
        printf("[IEC][CTL] write_coil01(%s) failed rc=%d\n", PV_CurtailEnable_COIL_NAME, rc);
        return CONTROL_RESULT_FAILED;
    }

    uint64_t ts = Hal_getTimeInMs();

    if (PV_CurtailEnable_T)
        IedServer_updateUTCTimeAttributeValue(ctx->srv, PV_CurtailEnable_T, ts);

    if (PV_CurtailEnable_STVAL)
        IedServer_updateAttributeValue(ctx->srv, PV_CurtailEnable_STVAL, value);

    printf("[IEC][CTL] CURTAILENABLE SUCCESS: coil=%d\n", coil01);

    return CONTROL_RESULT_OK;
}

/* Mirror IEC setpoints (DO1..DO4.setMag.f) -> Modbus HR points */
void iec_update_setpoints_to_modbus(IedServer srv, process_image_t* pi)
{
    static int init = 0;
    static float last[PV_SETPOINT_MAP_COUNT];

    if (!srv || !pi) return;

    if (!init) {
        for (int i = 0; i < PV_SETPOINT_MAP_COUNT; i++)
            last[i] = NAN;
        init = 1;
    }

    for (int i = 0; i < PV_SETPOINT_MAP_COUNT; i++) {
        DataAttribute* da = PV_SETPOINT_MAP[i].mag_f;
        if (!da) continue;

        float v = IedServer_getFloatAttributeValue(srv, da);

        if (isnan(last[i]) || fabsf(v - last[i]) > PV_SETPOINT_MAP[i].deadband) {

            pi_lock(pi);
            int rc = write_point_double(pi, PV_SETPOINT_MAP[i].modbus_name, (double)v);
            pi_unlock(pi);

            if (rc != 0)
                printf("[SP] write_point_double(%s) rc=%d\n", PV_SETPOINT_MAP[i].modbus_name, rc);
            else
                printf("[SP] %s = %.6f\n", PV_SETPOINT_MAP[i].modbus_name, v);

            if (rc == 0) last[i] = v;

        }
    }
}

/* Modbus -> IEC update loop (your working stuff) */
void iec_update_from_modbus(IedServer srv, process_image_t* pi)
{
    if (!srv || !pi)
        return;

    for (int i = 0; i < PV_FLOAT_MAP_COUNT; i++) {
        const MbToIecFloatMap* m = &PV_FLOAT_MAP[i];

        double v = 0.0;
        int rc;

        pi_lock(pi);
        rc = read_point_double(pi, m->modbus_name, &v);
        pi_unlock(pi);

        if (rc == 0) {
            float vf = (float)v;
            uint64_t ts = Hal_getTimeInMs();

            if (m->mag_f)
                IedServer_updateFloatAttributeValue(srv, m->mag_f, vf);

            if (m->t)
                IedServer_updateUTCTimeAttributeValue(srv, m->t, ts);
        }
    }

        /* NEW: print IEC-side state every 2s */
    iec_print_state(srv);
}

/* Start server */
IedServer iec_server_start(process_image_t* pi)
{
    IedServer srv = IedServer_create(&iedModel);

    IedServer_setServerIdentity(srv, "PV", "pv_device", "1.0");
    IedServer_setConnectionIndicationHandler(
        srv,
        (IedConnectionIndicationHandler) connectionHandler,
        NULL
    );

    /* Allow CO writes for control (Operate path) */
    IedServer_setWriteAccessPolicy(srv, IEC61850_FC_CO, ACCESS_POLICY_ALLOW);

    /* Allow SP writes so client can write DO1..DO4 */
    IedServer_setWriteAccessPolicy(srv, IEC61850_FC_SP, ACCESS_POLICY_ALLOW);

    /* ctlModel for CBPV */
    if (PV_CBPV_CTLMODEL) {
        IedServer_updateInt32AttributeValue(srv, PV_CBPV_CTLMODEL, 1);
        printf("[IEC] GGIO1.SPCSO1.ctlModel set to 1\n");
    }

    /* ctlModel for CurtailEnable */
    if (PV_CurtailEnable_CTLMODEL) {
        IedServer_updateInt32AttributeValue(srv, PV_CurtailEnable_CTLMODEL, 1);
        printf("[IEC] GGIO1.SPCSO2.ctlModel set to 1\n");
    }

    g_ctl.srv = srv;
    g_ctl.pi  = pi;

    /* Install control handler for CBPV */
    if (PV_CBPV_DO) {
        IedServer_setControlHandler(
            srv,
            PV_CBPV_DO,
            (ControlHandler) cbpv_control_handler,
            (void*) &g_ctl
        );
        printf("[IEC] Control handler installed for GGIO1.SPCSO1 (CBPV)\n");
    }

    /* Install control handler for CurtailEnable */
    if (PV_CurtailEnable_DO) {
        IedServer_setControlHandler(
            srv,
            PV_CurtailEnable_DO,
            (ControlHandler) curtailenable_control_handler,
            (void*) &g_ctl
        );
        printf("[IEC] Control handler installed for GGIO1.SPCSO2 (CurtailEnable)\n");
    }    

    /* Init IEC setpoints from Modbus (optional) */
    for (int i = 0; i < PV_SETPOINT_MAP_COUNT; i++) {
        double v = 0.0;
        pi_lock(pi);
        int rc = read_point_double(pi, PV_SETPOINT_MAP[i].modbus_name, &v);
        pi_unlock(pi);

        if (rc == 0 && PV_SETPOINT_MAP[i].mag_f) {
            IedServer_updateFloatAttributeValue(srv, PV_SETPOINT_MAP[i].mag_f, (float)v);
        }
    }

    IedServer_start(srv, 102);

    if (!IedServer_isRunning(srv)) {
        printf("[IEC] ERROR: failed to start server on port 102\n");
        IedServer_destroy(srv);
        return NULL;
    }

    running = 1;
    signal(SIGINT, sigint_handler);

    printf("[IEC] Server running on port 102\n");
    return srv;
}

void iec_server_stop(IedServer srv)
{
    if (!srv) return;

    IedServer_stop(srv);
    IedServer_destroy(srv);

    g_ctl.srv = NULL;
    g_ctl.pi  = NULL;
}
