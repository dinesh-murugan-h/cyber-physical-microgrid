// docker/devices/pcc1/ied/ied_server.c

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#include "iec61850_server.h"
#include "iec61850_common.h"

#include "hal_thread.h"
#include "hal_time.h"

#include "mms_value.h"

#include "static_model.h"
#include "device_map.h"

#include "process_image.h"
#include "printmap.h"   /* read_point_double/read_coil01/write_coil01 */



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

/* -----------------------------------------------------------------------------
 * Control handler for SPCS02 (synchStart)
 * - expects MMS_BOOLEAN
 * - writes Modbus coil "PCC1.synchStart"
 * - updates IEC stVal + t
 * -----------------------------------------------------------------------------
 */
static ControlHandlerResult
synchStart_control_handler(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    control_ctx_t* ctx = (control_ctx_t*) parameter;

    if (!ctx || !ctx->srv || !ctx->pi)
        return CONTROL_RESULT_FAILED;

    if (test) {
        printf("[IEC][CTL] synchStart TEST -> rejected\n");
        return CONTROL_RESULT_FAILED;
    }

    ClientConnection clientCon = ControlAction_getClientConnection(action);
    if (clientCon) {
        printf("[IEC][CTL] Control from client %s\n", ClientConnection_getPeerAddress(clientCon));
    }

    printf("[IEC][CTL] ctlNum=%i\n", ControlAction_getCtlNum(action));

    if (!value || MmsValue_getType(value) != MMS_BOOLEAN) {
        printf("[IEC][CTL] synchStart invalid type (expect BOOLEAN)\n");
        return CONTROL_RESULT_FAILED;
    }

    bool on = MmsValue_getBoolean(value);
    int coil01 = on ? 1 : 0;

    /* write to Modbus coil */
    pi_lock(ctx->pi);
    int rc = write_coil01(ctx->pi, PCC1_SYNCHSTART_COIL_NAME, coil01);
    pi_unlock(ctx->pi);

    if (rc != 0) {
        printf("[IEC][CTL] write_coil01(%s) failed rc=%d\n", PCC1_SYNCHSTART_COIL_NAME, rc);
        return CONTROL_RESULT_FAILED;
    }

    /* update IEC stVal + timestamp */
    uint64_t ts = Hal_getTimeInMs();

    if (PCC1_SYNCHSTART_T)
        IedServer_updateUTCTimeAttributeValue(ctx->srv, PCC1_SYNCHSTART_T, ts);

    if (PCC1_SYNCHSTART_STVAL) {
        /* updateAttributeValue copies internally; value is safe to reuse */
        IedServer_updateAttributeValue(ctx->srv, PCC1_SYNCHSTART_STVAL, value);
    }

    printf("[IEC][CTL] synchStart SUCCESS: coil=%d stVal=%d\n", coil01, coil01);

    return CONTROL_RESULT_OK;
}

/* ---- Modbus -> IEC update loop ---- */
void iec_update_from_modbus(IedServer srv, process_image_t* pi)
{
    if (!srv || !pi) return;

    static uint64_t last_print_ms = 0;
    uint64_t now_ms = Hal_getTimeInMs();

    bool do_print = false;
    if (now_ms - last_print_ms >= 1000) {
        last_print_ms = now_ms;
        do_print = true;
    }

    /* Update 8 analogue floats */
    for (int i = 0; i < PCC1_FLOAT_MAP_COUNT; i++) {

        const MbToIecFloatMap* m = &PCC1_FLOAT_MAP[i];

        double v = 0.0;
        int rc;

        pi_lock(pi);
        rc = read_point_double(pi, m->modbus_name, &v);
        pi_unlock(pi);

        if (rc == 0 && m->mag_f) {

            Timestamp iecTs;
            Timestamp_clearFlags(&iecTs);
            Timestamp_setTimeInMilliseconds(&iecTs, now_ms);
            Timestamp_setLeapSecondKnown(&iecTs, true);

            IedServer_lockDataModel(srv);

            if (m->t)
                IedServer_updateTimestampAttributeValue(srv, m->t, &iecTs);

            IedServer_updateFloatAttributeValue(srv, m->mag_f, (float)v);

            IedServer_unlockDataModel(srv);

            if (do_print) {
                printf("[MX] %-24s -> %-28s = %.6f\n", m->modbus_name, m->iec_path, v);
            }
        }
        else {
            if (do_print) {
                printf("[MX] read_point_double failed or DA NULL: %s rc=%d\n",
                       m->modbus_name, rc);
            }
        }
    }

    /* Track gridEnable status from Modbus (READ ONLY in IEC) */
    if (PCC1_GRIDENABLE_STVAL) {
        int coil01 = 0;
        int rc;

        pi_lock(pi);
        rc = read_coil01(pi, PCC1_GRIDENABLE_COIL_NAME, &coil01);
        pi_unlock(pi);

        if (rc == 0) {
            MmsValue* b = MmsValue_newBoolean(coil01 ? true : false);

            uint64_t ts = now_ms;
            if (PCC1_GRIDENABLE_T)
                IedServer_updateUTCTimeAttributeValue(srv, PCC1_GRIDENABLE_T, ts);

            IedServer_updateAttributeValue(srv, PCC1_GRIDENABLE_STVAL, b);
            MmsValue_delete(b);

            if (do_print) {
                printf("[SPC] gridEnable coil=%d -> stVal=%d\n", coil01, coil01);
            }
        }
        else if (do_print) {
            printf("[SPC] read_coil01 failed rc=%d\n", rc);
        }
    }

    /* Track synchStart status from Modbus (so IEC readback matches reality) */
    if (PCC1_SYNCHSTART_STVAL) {
        int coil01 = 0;
        int rc;

        pi_lock(pi);
        rc = read_coil01(pi, PCC1_SYNCHSTART_COIL_NAME, &coil01);
        pi_unlock(pi);

        if (rc == 0) {
            MmsValue* b = MmsValue_newBoolean(coil01 ? true : false);

            uint64_t ts = now_ms;
            if (PCC1_SYNCHSTART_T)
                IedServer_updateUTCTimeAttributeValue(srv, PCC1_SYNCHSTART_T, ts);

            IedServer_updateAttributeValue(srv, PCC1_SYNCHSTART_STVAL, b);
            MmsValue_delete(b);

            if (do_print) {
                printf("[SPC] synchStart coil=%d -> stVal=%d\n", coil01, coil01);
            }
        }
        else if (do_print) {
            printf("[SPC] read_coil01 failed rc=%d\n", rc);
        }
    }
}

/* ---- start/stop ---- */
IedServer iec_server_start(process_image_t* pi)
{
    if (!pi) return NULL;

    IedServer srv = IedServer_create(&iedModel);

    IedServer_setServerIdentity(srv, "PCC1", "pcc1_device", "1.0");
    IedServer_setConnectionIndicationHandler(
        srv,
        (IedConnectionIndicationHandler) connectionHandler,
        NULL
    );

    /* Allow CO writes for control (Operate path) */
    IedServer_setWriteAccessPolicy(srv, IEC61850_FC_CO, ACCESS_POLICY_ALLOW);

    /* Make sure control model is “direct-with-normal-security” for SPCS02 (synchStart) */
    if (PCC1_SYNCHSTART_CTLMODEL) {
        IedServer_updateInt32AttributeValue(srv, PCC1_SYNCHSTART_CTLMODEL, 1);
        printf("[IEC] GGIO1.SPCSO2.ctlModel set to 1 (direct-with-normal-security)\n");
    }

    /* init gridEnable stVal from Modbus coil (read-only) */
    if (PCC1_GRIDENABLE_STVAL) {
        int coil01 = 0;
        pi_lock(pi);
        (void) read_coil01(pi, PCC1_GRIDENABLE_COIL_NAME, &coil01);
        pi_unlock(pi);

        MmsValue* b = MmsValue_newBoolean(coil01 ? true : false);
        IedServer_updateAttributeValue(srv, PCC1_GRIDENABLE_STVAL, b);
        MmsValue_delete(b);
    }

    /* init synchStart stVal from Modbus coil */
    if (PCC1_SYNCHSTART_STVAL) {
        int coil01 = 0;
        pi_lock(pi);
        (void) read_coil01(pi, PCC1_SYNCHSTART_COIL_NAME, &coil01);
        pi_unlock(pi);

        MmsValue* b = MmsValue_newBoolean(coil01 ? true : false);
        IedServer_updateAttributeValue(srv, PCC1_SYNCHSTART_STVAL, b);
        MmsValue_delete(b);
    }

    g_ctl.srv = srv;
    g_ctl.pi  = pi;

    /* Install control handler ONLY for SPCS02 (synchStart) */
    if (PCC1_SYNCHSTART_DO) {
        IedServer_setControlHandler(
            srv,
            PCC1_SYNCHSTART_DO,
            (ControlHandler) synchStart_control_handler,
            (void*) &g_ctl
        );
        printf("[IEC] Control handler installed for GGIO1.SPCSO2 (synchStart)\n");
    }
    else {
        printf("[IEC] WARNING: PCC1_SYNCHSTART_DO is NULL; no control handler installed\n");
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
