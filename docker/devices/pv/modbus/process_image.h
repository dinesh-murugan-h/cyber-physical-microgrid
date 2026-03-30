#pragma once
#include <pthread.h>
#include <modbus/modbus.h>
#include "regmap.h"


typedef struct {
    pthread_mutex_t lock;
    const devmap_t* dev;         
    modbus_mapping_t* mb;        
} process_image_t;


static inline void pi_init(process_image_t* pi, const devmap_t* dev, modbus_mapping_t* mb)
{
    pi->dev = dev;
    pi->mb = mb;
    pthread_mutex_init(&pi->lock, NULL);
}

static inline void pi_destroy(process_image_t* pi)
{
    pthread_mutex_destroy(&pi->lock);
}


static inline void pi_lock(process_image_t* pi)   { pthread_mutex_lock(&pi->lock); }
static inline void pi_unlock(process_image_t* pi) { pthread_mutex_unlock(&pi->lock); }




int read_point_double(process_image_t* pi, const char* point_name, double* out_value);


int read_coil01(process_image_t* pi, const char* point_name, int* out_value01);


int write_coil01(process_image_t* pi, const char* point_name, int value01);
