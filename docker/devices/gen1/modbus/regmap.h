#pragma once
#include <stdint.h>
#include <stddef.h>

#define ARRAY_LEN(a) ((int)(sizeof(a) / sizeof((a)[0])))

/*
  IMPORTANT ABOUT ADDRESSES (Simulink vs Modbus wire)

  - Simulink Modbus block "Address" is 1-based in your setup.
  - Modbus protocol addresses on the wire are 0-based.
    So Simulink Address N <-> wire addr (N-1)

  In this regmap, pointdef_t.addr is the Simulink Address (1-based).
  Everywhere we index libmodbus arrays, we use (addr-1).
*/

/* Modbus area */
typedef enum {
    AREA_COIL     = 0,  // coils (1-bit)
    AREA_DISC_IN  = 1,  // discrete inputs (1-bit)
    AREA_HR       = 3,  // holding registers (16-bit words)
    AREA_IR       = 4   // input registers (16-bit words)
} area_t;

/* Access permission */
typedef enum {
    REG_RO = 0,
    REG_RW = 1
} reg_access_t;

/*
  Encoding / precision.
  Note: Modbus registers are 16-bit words.
  - int16/uint16 = 1 word
  - int32/uint32/single = 2 words
  - int64/uint64/double = 4 words
*/
typedef enum {
    ENC_BOOL   = 0,
    ENC_INT16  = 1,
    ENC_UINT16 = 2,
    ENC_INT32  = 3,
    ENC_UINT32 = 4,
    ENC_INT64  = 5,
    ENC_UINT64 = 6,
    ENC_SINGLE = 7,   // IEEE-754 float32 in 2 registers
    ENC_DOUBLE = 8    // IEEE-754 float64 in 4 registers
} enc_t;

/*
  Word order for multi-register values.

  For 32-bit types (2 regs):
    WO_2_AB = [r0 r1]
    WO_2_BA = [r1 r0]

  For 64-bit types (4 regs):
    WO_4_ABCD = [r0 r1 r2 r3]
    WO_4_DCBA = [r3 r2 r1 r0]
    WO_4_BADC = [r1 r0 r3 r2]   (swap pairs)
    WO_4_CDAB = [r2 r3 r0 r1]   (swap halves)

  byte_swap = swap bytes inside each 16-bit register (rare but seen).
*/
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

/* One point */
typedef struct {
    area_t area;
    uint16_t addr;          // Simulink "Address" (1-based). Wire address = addr-1.
    reg_access_t access;

    enc_t enc;
    const char* name;
    const char* unit;
    float scale;

    /* For float types, these control decoding */
    word_order_2_t wo2;     // used when enc is ENC_SINGLE
    word_order_4_t wo4;     // used when enc is ENC_DOUBLE
    uint8_t byte_swap;      // 0 = normal, 1 = swap bytes within each 16-bit word

    int64_t raw_min;
    int64_t raw_max;

    uint64_t init_raw;
} pointdef_t;

/* One device map */
typedef struct {
    int unit_id;
    const char* device_name;
    const pointdef_t* points;
    int point_count;
} devmap_t;

/* -------------------------
   Helpers
   ------------------------- */

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

/* =========================================================
   DEVICE 1 (unit_id=1): GEN1
   ========================================================= */

/*
  IMPORTANT:
  You MUST set the correct wo4/byte_swap for Simulink double.

  Start with:
    wo4 = WO_4_ABCD
    byte_swap = 0

  If values are wrong, you flip ONLY these in the 3 points (v/i/phi),
  until it matches. (printmap will print raw words to help.)
*/

static const pointdef_t GEN1_POINTS[] = {
    /* area      addr acc    enc         name              unit  scale  wo2       wo4         byte_swap  raw_min         raw_max         init */
    { AREA_HR,    1,  REG_RW, ENC_DOUBLE, "GEN1.P_gen1",  "V",  1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    5,  REG_RW, ENC_DOUBLE, "GEN1.P_gen1_pu",  "V",  1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    9,  REG_RW, ENC_DOUBLE, "GEN1.V_gen1_pu",  "A",    1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    13,  REG_RW, ENC_DOUBLE, "GEN1.Q_gen1_pu", "A",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    17,  REG_RW, ENC_DOUBLE, "GEN1.freq_gen1_pu", "rad",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    21,  REG_RW, ENC_DOUBLE, "GEN1.PrefG1", "rad",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    25,  REG_RW, ENC_DOUBLE, "GEN1.DroopPG1", "rad",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,    29,  REG_RW, ENC_DOUBLE, "GEN1.QrefG1", "kVAr",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_HR,  34,  REG_RW, ENC_DOUBLE, "GEN1.DroopQG1", "",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL },
    { AREA_COIL,  38,  REG_RW, ENC_BOOL, "GEN1.CBG1", "",   1.0f, WO_2_AB,  WO_4_ABCD,  0,        (int64_t)-9e18, (int64_t)9e18, 0ULL }
};


static const devmap_t DEVICE = {
    .unit_id = 1,
    .device_name = "GEN1",
    .points = GEN1_POINTS,
    .point_count = ARRAY_LEN(GEN1_POINTS),
};

static inline const devmap_t* get_devmap(void)
{
    return &DEVICE;
}

