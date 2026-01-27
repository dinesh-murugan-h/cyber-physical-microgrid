#pragma once
#include <modbus/modbus.h>
#include "regmap.h"
#include "process_image.h"

void print_device_points(const devmap_t* dev);
void print_device_state(const devmap_t* dev, const modbus_mapping_t* mb);

/* See process_image.h for docs (implemented in printmap.c) */
int read_point_double(process_image_t* pi, const char* point_name, double* out_value);
int read_coil01(process_image_t* pi, const char* point_name, int* out_value01);
int write_coil01(process_image_t* pi, const char* point_name, int value01);
