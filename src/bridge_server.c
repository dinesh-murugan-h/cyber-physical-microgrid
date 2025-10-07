#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/select.h>

#include <modbus.h>
#include <iec61850_server.h>
#include <hal_thread.h>
#include "static_model.h"

/* --- Control handler for GGIO1.SPCSO1 (accept Operate from MATLAB) --- */
static ControlHandlerResult controlHandler_SPCSO1(ControlAction action, void* parameter, MmsValue* value, bool test)
{
    if (test)
        return CONTROL_RESULT_OK;

    bool newState = MmsValue_getBoolean(value);
    uint64_t now = Hal_getTimeInMs();

    printf("Received Operate() for GGIO1.SPCSO1 -> %s\n", newState ? "ON" : "OFF");

    IedServer_updateBooleanAttributeValue((IedServer)parameter,
        IEDMODEL_GenericIO_GGIO1_SPCSO1_stVal, newState);
    IedServer_updateUTCTimeAttributeValue((IedServer)parameter,
        IEDMODEL_GenericIO_GGIO1_SPCSO1_t, now);
    IedServer_updateQuality((IedServer)parameter,
        IEDMODEL_GenericIO_GGIO1_SPCSO1_q, QUALITY_VALIDITY_GOOD);

    return CONTROL_RESULT_OK;
}


static bool running = true;

// Helper to read IEEE754 double (64-bit) from 4 Modbus registers (23-26)
double read_double_from_registers(modbus_mapping_t *mb_mapping) {
    if (mb_mapping == NULL) return 0.0;
    
    // Read 4 registers starting from 23
    uint16_t regs[4];
    regs[0] = mb_mapping->tab_registers[23];
    regs[1] = mb_mapping->tab_registers[24];
    regs[2] = mb_mapping->tab_registers[25];
    regs[3] = mb_mapping->tab_registers[26];
    
    // Combine into 64-bit value (big-endian)
    uint64_t raw = ((uint64_t)regs[0] << 48) | 
                   ((uint64_t)regs[1] << 32) | 
                   ((uint64_t)regs[2] << 16) | 
                   (uint64_t)regs[3];
    
    // Convert to double (big-endian)
    double result;
    memcpy(&result, &raw, sizeof(double));
    
    return result;
}





void handle_signal(int sig) { (void)sig; running = false; }

/* Helper: set a socket to non-blocking */
static int set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) return -1;
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) return -1;
    return 0;
}

/* Custom non-blocking modbus receive */
static int modbus_receive_nonblocking(modbus_t *ctx, uint8_t *query) {
    int rc;
    
    // Try to receive data
    rc = modbus_receive(ctx, query);
    
    // Handle non-blocking case
    if (rc == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            return 0; // No data available
        } else {
            return -1; // Real error
        }
    }
    
    return rc;
}

/* ---------- IEC 61850 connection handler ---------- */
static void connectionHandler(IedServer self, ClientConnection connection,
                              bool connected, void* parameter)
{
    (void)self; (void)connection; (void)parameter;
    printf("IEC 61850 client %s!\n", connected ? "connected" : "disconnected");
}

/* ---------- Modbus setup ---------- */
int start_modbus_server(modbus_t **ctx_out, modbus_mapping_t **map_out, int *server_socket_out) {
    *ctx_out = modbus_new_tcp("0.0.0.0", 1502);
    if (*ctx_out == NULL) {
        fprintf(stderr, "Unable to create Modbus context\n");
        return -1;
    }

    // Set Modbus to non-blocking mode
    modbus_set_response_timeout(*ctx_out, 0, 100000); // 100ms timeout

    *server_socket_out = modbus_tcp_listen(*ctx_out, 5);
    if (*server_socket_out == -1) {
        fprintf(stderr, "Unable to listen on port 1502\n");
        modbus_free(*ctx_out);
        return -1;
    }
    
    // Set server socket to non-blocking
    if (set_nonblocking(*server_socket_out) == -1) {
        fprintf(stderr, "Failed to set server socket non-blocking\n");
        close(*server_socket_out);
        modbus_free(*ctx_out);
        return -1;
    }
    
    printf("Modbus server listening on port 1502...\n");

    *map_out = modbus_mapping_new(0, 0, 100, 0);
    if (*map_out == NULL) {
        fprintf(stderr, "Failed to allocate modbus mapping\n");
        close(*server_socket_out);
        modbus_free(*ctx_out);
        return -1;
    }
    return 0;
}

/* ---------- IEC 61850 setup ---------- */
IedServer start_ied_server(void) {
    IedServer iedServer = IedServer_create(&iedModel);
    if (!iedServer) { fprintf(stderr, "Failed to create IED server!\n"); return NULL; }

    /* Allow writes to typical control/measure classes incl. SP for setpoints */
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_MX, ACCESS_POLICY_ALLOW);
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_ST, ACCESS_POLICY_ALLOW);
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_CO, ACCESS_POLICY_ALLOW);
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_DC, ACCESS_POLICY_ALLOW);
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_SP, ACCESS_POLICY_ALLOW);
    IedServer_setWriteAccessPolicy(iedServer, IEC61850_FC_CF, ACCESS_POLICY_ALLOW);

    IedServer_setConnectionIndicationHandler(iedServer, connectionHandler, NULL);

    IedServer_setControlHandler(
    iedServer,
    IEDMODEL_GenericIO_GGIO1_SPCSO1,
    (ControlHandler)controlHandler_SPCSO1,
    iedServer);

    

    IedServer_start(iedServer, 102);
    if (!IedServer_isRunning(iedServer)) {
        fprintf(stderr, "Error: could not start IED server on port 102\n");
        IedServer_destroy(iedServer);
        return NULL;
    }

    printf("IEC 61850 IED server running on port 102...\n");
    return iedServer;
}

/* ---------- Main ---------- */
int main(void) {
    signal(SIGINT, handle_signal);
    printf("Bridge server starting...\n");

    /* Start Modbus */
    modbus_t *ctx = NULL;
    modbus_mapping_t *mb_mapping = NULL;
    int server_socket;
    if (start_modbus_server(&ctx, &mb_mapping, &server_socket) != 0)
        return -1;

    /* Start IEC 61850 */
    IedServer iedServer = start_ied_server();
    if (!iedServer) {
        modbus_mapping_free(mb_mapping);
        close(server_socket);
        modbus_free(ctx);
        return -1;
    }

    /* Track a single client socket for simplicity */
    int client_socket = -1;
    uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];

    /* Optional: initialize mirror registers */
    mb_mapping->tab_registers[10] = 0;   /* Modbus -> 61850 input mirror */
    mb_mapping->tab_registers[23] = 0;   /* 61850 -> Modbus duty cycle */

    while (running) {
        fd_set rfds;
        FD_ZERO(&rfds);
        int maxfd = -1;

        /* Always watch server socket for new connections */
        FD_SET(server_socket, &rfds);
        maxfd = (server_socket > maxfd) ? server_socket : maxfd;

        /* Watch client socket if connected */
        if (client_socket >= 0) {
            FD_SET(client_socket, &rfds);
            maxfd = (client_socket > maxfd) ? client_socket : maxfd;
        }

        struct timeval tv = { .tv_sec = 0, .tv_usec = 100000 }; /* 100 ms tick */
        int nready = select(maxfd + 1, &rfds, NULL, NULL, &tv);

        if (nready > 0) {
            /* New client connection */
            if (FD_ISSET(server_socket, &rfds)) {
                if (client_socket >= 0) {
                    // We already have a client, reject new connection
                    int tmp_sock = modbus_tcp_accept(ctx, &server_socket);
                    if (tmp_sock != -1) {
                        printf("Rejecting new Modbus client (only one allowed)\n");
                        close(tmp_sock);
                    }
                } else {
                    // Accept new client
                    int s = modbus_tcp_accept(ctx, &server_socket);
                    if (s != -1) {
                        if (set_nonblocking(s) == -1) {
                            perror("fcntl O_NONBLOCK");
                            close(s);
                        } else {
                            client_socket = s;
                            modbus_set_socket(ctx, client_socket);
                            printf("Modbus client connected!\n");
                        }
                    }
                }
            }

            /* Existing client has data */
            if (client_socket >= 0 && FD_ISSET(client_socket, &rfds)) {
                int rc = modbus_receive_nonblocking(ctx, query);
                if (rc > 0) {
                    // Process complete Modbus frame
                    modbus_reply(ctx, query, rc, mb_mapping);
                    printf("Processed Modbus request\n");
                } else if (rc == -1) {
                    // Client disconnected or error
                    printf("Modbus client disconnected (errno=%d: %s)\n", errno, strerror(errno));
                    close(client_socket);
                    client_socket = -1;
                    modbus_set_socket(ctx, -1);
                }
                // rc == 0 means no complete frame yet, continue
            }
        } else if (nready == -1) {
            // select error
            if (errno != EINTR) {
                perror("select");
                break;
            }
        }

        /* IEC 61850 data processing */
        IedServer_lockDataModel(iedServer);

         /* --- Read SPCSO1.stVal (breaker/switch state) written by MATLAB operate() --- */
        MmsValue* stValVal = IedServer_getAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO1_stVal);
        if (stValVal != NULL) {
            bool newState = MmsValue_getBoolean(stValVal);

            printf("GGIO1.SPCSO1.stVal = %s\n", newState ? "ON (1)" : "OFF (0)");

            /* Update timestamp and quality just like beagle_demo.c */
            uint64_t now = Hal_getTimeInMs();
            IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO1_t, now);
            IedServer_updateQuality(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO1_q, QUALITY_VALIDITY_GOOD);
        }




        MmsValue* vendorVal = IedServer_getAttributeValue(
            iedServer,
            IEDMODEL_GenericIO_GGIO1_NamPlt_vendor
        );

        const char* vendorStr = NULL;

        if (vendorVal) {
            vendorStr = MmsValue_toString(vendorVal);
            printf("Desired Voltage = %s\n", vendorStr);
        }

        if (vendorStr) {
            int vendorInt = atoi(vendorStr);
            // Calculate duty cycle
            float dutyCycle = (float) vendorInt / (vendorInt + 20.0f);
            printf("Duty Cycle = %.3f\n", dutyCycle);

            // Scale to integer 
            int dutyScaled = (int)(dutyCycle * 10000);

            // Store into Modbus holding register 23
            mb_mapping->tab_registers[22] = dutyScaled;

            printf("Duty cycle (scaled) written to Modbus reg[23] = %d\n", dutyScaled);
        }


double ActualVoltage = read_double_from_registers(mb_mapping);

// Convert double to float for MmsValue
float voltage_float = (float)ActualVoltage;

MmsValue* fval = MmsValue_newFloat(voltage_float);
IedServer_updateAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_AnIn1_mag_f, fval);
printf("Sent Actual Voltage: %f to scada (from regs 23-26)\n", voltage_float);
MmsValue_delete(fval);

        IedServer_unlockDataModel(iedServer);

        // Small sleep 
        Thread_sleep(100);
    }

    printf("Shutting down...\n");

    // Cleanup Modbus
    if (client_socket >= 0) {
        close(client_socket);
    }
    modbus_mapping_free(mb_mapping);
    close(server_socket);
    modbus_free(ctx);

    // Cleanup IEC 61850
    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);

    printf("Bridge server stopped.\n");
    return 0;
}