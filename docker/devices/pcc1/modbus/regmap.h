#pragma once
#include <stdint.h>
#include <stddef.h>

#define ARRAY_LEN(a) ((int)(sizeof(a) / sizeof((a)[0])))




typedef enum {
    AREA_COIL     = 0,  
    AREA_DISC_IN  = 1,  
    AREA_HR       = 3,  
    AREA_IR       = 4   
} area_t;


typedef enum {
    REG_RO = 0,
    REG_RW = 1
} reg_access_t;


typedef enum {
    ENC_BOOL   = 0,
    ENC_INT16  = 1,
    ENC_UINT16 = 2,
    ENC_INT32  = 3,
    ENC_UINT32 = 4,
    ENC_INT64  = 5,
    ENC_UINT64 = 6,
    ENC_SINGLE = 7,   
    ENC_DOUBLE = 8    
} enc_t;


typedef enum {
    WO_2_AB = 0,
    WO_2_BA = 1
} word_order_2_t;

typedef enum {
    WO_4_ABCD = 0,
    WO_4_DCBA = 1,
    WO_4_BADC = 2,
    WO_4_CDAB = 3
} word_order_4_t;


typedef struct {
    area_t area;
    uint16_t addr;          
    reg_access_t access;

    enc_t enc;
    const char* name;
    const char* unit;
    float scale;

   
    word_order_2_t wo2;     
    word_order_4_t wo4;     
    uint8_t byte_swap;      

    int64_t raw_min;
    int64_t raw_max;

    uint64_t init_raw;
} pointdef_t;


typedef struct {
    int unit_id;
    const char* device_name;
    const pointdef_t* points;
    int point_count;
} devmap_t;



static inline int enc_words(enc_t enc)
{
    switch (enc) {
    case ENC_INT16:
    case ENC_UINT16:
    case ENC_BOOL:
        return 1;
    case ENC_INT32:
    case ENC_UINT32:
    case ENC_SINGLE:
        return 2;
    case ENC_INT64:
    case ENC_UINT64:
    case ENC_DOUBLE:
        return 4;
    default:
        return 1;
    }
}

static inline int enc_is_float(enc_t enc)
{
    return (enc == ENC_SINGLE) || (enc == ENC_DOUBLE);
}

static inline uint16_t addr_wire0(const pointdef_t* p)
{
    if (!p) return 0;
    if (p->addr == 0) return 0;
    return (uint16_t)(p->addr - 1);
}

static inline int point_covers_wire_addr(const pointdef_t* p, uint16_t wire_addr0)
{
    if (!p) return 0;

    uint16_t base = addr_wire0(p);
    int w = 1;
    if (p->area == AREA_HR || p->area == AREA_IR)
        w = enc_words(p->enc);

    return (wire_addr0 >= base) && (wire_addr0 < (uint16_t)(base + (uint16_t)w));
}

static inline int point_raw_in_range_i64(const pointdef_t* p, int64_t raw)
{
    if (!p) return 0;
    return (raw >= p->raw_min) && (raw <= p->raw_max);
}

static inline const pointdef_t* find_point_by_wire(const devmap_t* dev, area_t area, uint16_t wire_addr0)
{
    if (!dev) return NULL;
    for (int i = 0; i < dev->point_count; i++) {
        const pointdef_t* p = &dev->points[i];
        if (p->area != area) continue;
        if (point_covers_wire_addr(p, wire_addr0))
            return p;
    }
    return NULL;
}





static const pointdef_t PCC1_POINTS[] = {
   
    { AREA_HR,    1,  REG_RW, ENC_DOUBLE, "PCC1.vUtility_rms",  "V",  1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    5,  REG_RW, ENC_DOUBLE, "PCC1.vMicro_rms",  "V",  1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    9,  REG_RW, ENC_DOUBLE, "PCC1.iUtility_rms",  "A",    1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    13,  REG_RW, ENC_DOUBLE, "PCC1.iMicro_rms", "A",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    17,  REG_RW, ENC_DOUBLE, "PCC1.phiUtility", "rad",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    21,  REG_RW, ENC_DOUBLE, "PCC1.phiMicro", "rad",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    25,  REG_RW, ENC_DOUBLE, "PCC1.PGrid", "rad",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    29,  REG_RW, ENC_DOUBLE, "PCC1.QGrid", "kVAr",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_COIL,  34,  REG_RW, ENC_BOOL, "PCC1.gridEnable", "",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_COIL,  38,  REG_RW, ENC_BOOL, "PCC1.synchStart", "",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL }
};


static const devmap_t DEVICE = {
    .unit_id = 1,
    .device_name = "PCC1",
    .points = PCC1_POINTS,
    .point_count = ARRAY_LEN(PCC1_POINTS),
};

static inline const devmap_t* get_devmap(void)
{
    return &DEVICE;
}

