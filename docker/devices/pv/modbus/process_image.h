#pragma once
#include <pthread.h>
#include <modbus/modbus.h>
#include "regmap.h"

/* Shared state between Modbus + IEC server */
typedef struct {
    pthread_mutex_t lock;
    const devmap_t* dev;          /* from regmap.h */
    modbus_mapping_t* mb;         /* libmodbus mapping table */
} process_image_t;

/* init/destroy */
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

/* lock helpers */
static inline void pi_lock(process_image_t* pi)   { pthread_mutex_lock(&pi->lock); }
static inline void pi_unlock(process_image_t* pi) { pthread_mutex_unlock(&pi->lock); }

/* --------------------------------------------------------------------------
   Convenience accessors by point name (engineering values)
   --------------------------------------------------------------------------
   These functions operate on the shared process image (pi->mb) using the point
   definitions in pi->dev (regmap.h). They DO NOT lock/unlock internally.
   Caller is expected to do:
       pi_lock(&pi); ...; pi_unlock(&pi);

   Return 0 on success, non-zero on error.
*/

/* Read any point (HR/IR/COIL) as engineering double (decoded * scale). */
int read_point_double(process_image_t* pi, const char* point_name, double* out_value);

/* Read a coil point as 0/1. */
int read_coil01(process_image_t* pi, const char* point_name, int* out_value01);

/* Write a coil point as 0/1. */
int write_coil01(process_image_t* pi, const char* point_name, int value01);
