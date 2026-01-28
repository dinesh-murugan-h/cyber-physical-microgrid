// docker/devices/gen2/ied/ied_server.c

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
        { "GGIO1.AnIn1.mag.f (P_gen2)",      IEDMODEL_GEN2LD0_GGIO1_AnIn1_mag_f },
        { "GGIO1.AnIn2.mag.f (P_gen2_pu)",   IEDMODEL_GEN2LD0_GGIO1_AnIn2_mag_f },
        { "GGIO1.AnIn3.mag.f (V_gen2_pu)",   IEDMODEL_GEN2LD0_GGIO1_AnIn3_mag_f },
        { "GGIO1.AnIn4.mag.f (Q_gen2_pu)",   IEDMODEL_GEN2LD0_GGIO1_AnIn4_mag_f },
        { "GGIO1.AnIn5.mag.f (freq_pu)",     IEDMODEL_GEN2LD0_GGIO1_AnIn5_mag_f },
        { "GGIO1.AnIn6.mag.f (DroopPG2)",     IEDMODEL_GEN2LD0_GGIO1_AnIn6_mag_f },
        { "GGIO1.AnIn7.mag.f (DroopQG2)",     IEDMODEL_GEN2LD0_GGIO1_AnIn7_mag_f },
    };

    for (unsigned i = 0; i < (unsigned)(sizeof(anin)/sizeof(anin[0])); i++) {
        float v = IedServer_getFloatAttributeValue(srv, anin[i].mag_f);
        printf("[MX] %-28s = %.6f\n", anin[i].name, (double)v);
    }

    /* ---- SP: DO1..DO4.setMag.f ---- */
    for (int i = 0; i < GEN2_SETPOINT_MAP_COUNT; i++) {
        if (!GEN2_SETPOINT_MAP[i].mag_f) continue;
        float v = IedServer_getFloatAttributeValue(srv, GEN2_SETPOINT_MAP[i].mag_f);
        printf("[SP] %-28s = %.6f  (-> %s)\n",
               (GEN2_SETPOINT_MAP[i].modbus_name ? GEN2_SETPOINT_MAP[i].modbus_name : "setpoint"),
               (double)v,
               GEN2_SETPOINT_MAP[i].modbus_name ? GEN2_SETPOINT_MAP[i].modbus_name : "(null)");
    }

    /* ---- CO status: CBG2.stVal ---- */
    if (GEN2_CBG2_STVAL) {
        MmsValue* mv = IedServer_getAttributeValue(srv, GEN2_CBG2_STVAL);
        if (mv && MmsValue_getType(mv) == MMS_BOOLEAN) {
            bool b = MmsValue_getBoolean(mv);
            printf("[CO] GGIO1.SPCSO1.stVal (CBG2) = %d\n", b ? 1 : 0);
        } else if (mv) {
            printf("[CO] GGIO1.SPCSO1.stVal (CBG2) type=%d\n", (int)MmsValue_getType(mv));
        } else {
            printf("[CO] GGIO1.SPCSO1.stVal (CBG2) = (null)\n");
        }
    }

    if (GEN2_CBG2_CTLMODEL) {
        int32_t cm = IedServer_getInt32AttributeValue(srv, GEN2_CBG2_CTLMODEL);
        printf("[CF] GGIO1.SPCSO1.ctlModel = %d\n", (int)cm);
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

/* Control handler: CBG2 (SPCS01) -> Modbus coil */
static ControlHandlerResult
cbg2_control_handler(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    (void) action;

    control_ctx_t* ctx = (control_ctx_t*) parameter;

    if (!ctx || !ctx->srv || !ctx->pi)
        return CONTROL_RESULT_FAILED;

    if (test) {
        printf("[IEC][CTL] CBG2 TEST -> rejected\n");
        return CONTROL_RESULT_FAILED;
    }

    if (!value || MmsValue_getType(value) != MMS_BOOLEAN) {
        printf("[IEC][CTL] CBG2 invalid type (expect BOOLEAN)\n");
        return CONTROL_RESULT_FAILED;
    }

    bool on = MmsValue_getBoolean(value);
    int coil01 = on ? 1 : 0;

    pi_lock(ctx->pi);
    int rc = write_coil01(ctx->pi, GEN2_CBG2_COIL_NAME, coil01);
    pi_unlock(ctx->pi);

    if (rc != 0) {
        printf("[IEC][CTL] write_coil01(%s) failed rc=%d\n", GEN2_CBG2_COIL_NAME, rc);
        return CONTROL_RESULT_FAILED;
    }

    uint64_t ts = Hal_getTimeInMs();

    if (GEN2_CBG2_T)
        IedServer_updateUTCTimeAttributeValue(ctx->srv, GEN2_CBG2_T, ts);

    if (GEN2_CBG2_STVAL)
        IedServer_updateAttributeValue(ctx->srv, GEN2_CBG2_STVAL, value);

    printf("[IEC][CTL] CBG2 SUCCESS: coil=%d\n", coil01);

    return CONTROL_RESULT_OK;
}

/* Mirror IEC setpoints (DO1..DO4.setMag.f) -> Modbus HR points */
void iec_update_setpoints_to_modbus(IedServer srv, process_image_t* pi)
{
    static int init = 0;
    static float last[GEN2_SETPOINT_MAP_COUNT];

    if (!srv || !pi) return;

    if (!init) {
        for (int i = 0; i < GEN2_SETPOINT_MAP_COUNT; i++)
            last[i] = NAN;
        init = 1;
    }

    for (int i = 0; i < GEN2_SETPOINT_MAP_COUNT; i++) {
        DataAttribute* da = GEN2_SETPOINT_MAP[i].mag_f;
        if (!da) continue;

        float v = IedServer_getFloatAttributeValue(srv, da);

        if (isnan(last[i]) || fabsf(v - last[i]) > GEN2_SETPOINT_MAP[i].deadband) {

            pi_lock(pi);
            int rc = write_point_double(pi, GEN2_SETPOINT_MAP[i].modbus_name, (double)v);
            pi_unlock(pi);

            if (rc != 0)
                printf("[SP] write_point_double(%s) rc=%d\n", GEN2_SETPOINT_MAP[i].modbus_name, rc);
            else
                printf("[SP] %s = %.6f\n", GEN2_SETPOINT_MAP[i].modbus_name, v);

            if (rc == 0) last[i] = v;

        }
    }
}

/* Modbus -> IEC update loop (your working stuff) */
void iec_update_from_modbus(IedServer srv, process_image_t* pi)
{
    if (!srv || !pi)
        return;

    for (int i = 0; i < GEN2_FLOAT_MAP_COUNT; i++) {
        const MbToIecFloatMap* m = &GEN2_FLOAT_MAP[i];

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

    IedServer_setServerIdentity(srv, "GEN2", "gen2_device", "1.0");
    IedServer_setConnectionIndicationHandler(
        srv,
        (IedConnectionIndicationHandler) connectionHandler,
        NULL
    );

    /* Allow CO writes for control (Operate path) */
    IedServer_setWriteAccessPolicy(srv, IEC61850_FC_CO, ACCESS_POLICY_ALLOW);

    /* Allow SP writes so client can write DO1..DO4 */
    IedServer_setWriteAccessPolicy(srv, IEC61850_FC_SP, ACCESS_POLICY_ALLOW);

    /* ctlModel for CBG2 */
    if (GEN2_CBG2_CTLMODEL) {
        IedServer_updateInt32AttributeValue(srv, GEN2_CBG2_CTLMODEL, 1);
        printf("[IEC] GGIO1.SPCSO1.ctlModel set to 1\n");
    }

    g_ctl.srv = srv;
    g_ctl.pi  = pi;

    /* Install control handler for CBG2 */
    if (GEN2_CBG2_DO) {
        IedServer_setControlHandler(
            srv,
            GEN2_CBG2_DO,
            (ControlHandler) cbg2_control_handler,
            (void*) &g_ctl
        );
        printf("[IEC] Control handler installed for GGIO1.SPCSO1 (CBG2)\n");
    }

    /* Init IEC setpoints from Modbus (optional) */
    for (int i = 0; i < GEN2_SETPOINT_MAP_COUNT; i++) {
        double v = 0.0;
        pi_lock(pi);
        int rc = read_point_double(pi, GEN2_SETPOINT_MAP[i].modbus_name, &v);
        pi_unlock(pi);

        if (rc == 0 && GEN2_SETPOINT_MAP[i].mag_f) {
            IedServer_updateFloatAttributeValue(srv, GEN2_SETPOINT_MAP[i].mag_f, (float)v);
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
