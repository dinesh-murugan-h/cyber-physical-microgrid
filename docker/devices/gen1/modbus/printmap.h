
#pragma once

#include "process_image.h"


int read_point_double(process_image_t* pi, const char* point_name, double* out_val);
int read_coil01(process_image_t* pi, const char* coil_name, int* out_bit);
int write_coil01(process_image_t* pi, const char* coil_name, int bit);


int write_point_double(process_image_t* pi, const char* point_name, double value);


