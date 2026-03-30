
#pragma once

#include "iec61850_server.h"
#include "process_image.h"


IedServer iec_server_start(process_image_t* pi);


void iec_server_stop(IedServer srv);


void iec_update_from_modbus(IedServer srv, process_image_t* pi);


void iec_update_setpoints_to_modbus(IedServer srv, process_image_t* pi);
