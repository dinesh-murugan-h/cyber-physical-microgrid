#pragma once
#include <stdbool.h>
#include "process_image.h"

/*
 * Run Modbus TCP server (blocking call).
 * - unit_id: your device unit-id (argv[1] before)
 * - bind_ip: "0.0.0.0" typically
 * - port: 502 typically
 * - out_pi: filled with pointers to dev + mb (shared process image)
 *
 * Returns 0 on clean exit, non-zero on error.
 */
int modbus_server_run(int unit_id, const char* bind_ip, int port, process_image_t* out_pi);
