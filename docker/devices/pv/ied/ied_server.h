// docker/devices/PV/ied/ied_server.h
#pragma once

#include "iec61850_server.h"
#include "process_image.h"

/* Start IEC61850 server on port 102, register handlers, return server handle */
IedServer iec_server_start(process_image_t* pi);

/* Stop/destroy server */
void iec_server_stop(IedServer srv);

/* Periodic Modbus -> IEC updates (SCADA reads) */
void iec_update_from_modbus(IedServer srv, process_image_t* pi);

/* Periodic IEC (SP DO1..DO4) -> Modbus setpoint writes */
void iec_update_setpoints_to_modbus(IedServer srv, process_image_t* pi);
