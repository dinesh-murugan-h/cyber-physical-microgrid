#pragma once
#include <stdbool.h>
#include "process_image.h"


int modbus_server_run(int unit_id, const char* bind_ip, int port, process_image_t* out_pi);
