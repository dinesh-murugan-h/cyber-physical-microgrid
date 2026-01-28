// docker/devices/PV/device_main.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

#include "modbus_server.h"
#include "process_image.h"
#include "ied/ied_server.h"

static volatile int running = 1;

static void sigint_handler(int sig)
{
    (void)sig;
    running = 0;
}

static void* modbus_thread_fn(void* arg)
{
    process_image_t* pi = (process_image_t*)arg;
    (void)modbus_server_run(1, "0.0.0.0", 502, pi);
    return NULL;
}

int main(int argc, char** argv)
{
    (void)argc; (void)argv;
    setvbuf(stdout, NULL, _IOLBF, 0);

    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigint_handler);

    static process_image_t pi; /* initialized inside modbus_server_run */

    pthread_t modbus_thread;
    if (pthread_create(&modbus_thread, NULL, modbus_thread_fn, &pi) != 0) {
        printf("[DEVICE] failed to start modbus thread\n");
        return 1;
    }

    /* Wait until modbus thread has called pi_init */
    while (running && (pi.mb == NULL || pi.dev == NULL))
        usleep(10 * 1000);

    if (!running) {
        printf("[DEVICE] interrupted before servers started\n");
        return 0;
    }

    IedServer iedServer = iec_server_start(&pi);
    if (!iedServer) {
        printf("[DEVICE] IEC server failed to start\n");
        running = 0;
    }

    printf("[DEVICE] Modbus server running on port 502\n");

    while (running) {
        /* shared PI -> IEC (SCADA reads) */
        iec_update_from_modbus(iedServer, &pi);
        iec_update_setpoints_to_modbus(iedServer, &pi);  /* new: IEC DO1..DO4 -> Modbus setpoints */
        usleep(200 * 1000);
    }

    printf("[DEVICE] stopping...\n");
    iec_server_stop(iedServer);

    pthread_join(modbus_thread, NULL);
    return 0;
}
