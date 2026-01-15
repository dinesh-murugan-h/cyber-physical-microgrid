#pragma once
#include <modbus/modbus.h>
#include "regmap.h"

void print_device_state(const devmap_t* dev, const modbus_mapping_t* mb);
