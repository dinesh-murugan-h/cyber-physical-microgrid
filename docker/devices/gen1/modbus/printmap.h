// docker/devices/gen1/modbus/printmap.h
#pragma once

#include "process_image.h"

/* Existing functions you already use */
int read_point_double(process_image_t* pi, const char* point_name, double* out_val);
int read_coil01(process_image_t* pi, const char* coil_name, int* out_bit);
int write_coil01(process_image_t* pi, const char* coil_name, int bit);

/* ADD: generic write for HR points (ENC_DOUBLE, ENC_BOOL, etc.) */
int write_point_double(process_image_t* pi, const char* point_name, double value);


