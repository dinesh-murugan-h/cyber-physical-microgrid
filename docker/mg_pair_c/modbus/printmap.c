#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "printmap.h"

/* set to 1 if you want raw register dumps every print */
#ifndef PRINT_RAW_WORDS
#define PRINT_RAW_WORDS 1
#endif

static inline int host_is_little_endian(void)
{
    const uint16_t x = 1;
    return *((const uint8_t*)&x) == 1;
}

static inline uint16_t maybe_swap_bytes16(uint16_t w, uint8_t byte_swap)
{
    if (!byte_swap) return w;
    return (uint16_t)((w << 8) | (w >> 8));
}

static void reorder2(uint16_t in0, uint16_t in1, word_order_2_t wo, uint16_t out[2])
{
    if (wo == WO_2_BA) { out[0] = in1; out[1] = in0; }
    else              { out[0] = in0; out[1] = in1; }
}

static void reorder4(uint16_t r0, uint16_t r1, uint16_t r2, uint16_t r3, word_order_4_t wo, uint16_t out[4])
{
    switch (wo) {
    default:
    case WO_4_ABCD: out[0]=r0; out[1]=r1; out[2]=r2; out[3]=r3; break;
    case WO_4_DCBA: out[0]=r3; out[1]=r2; out[2]=r1; out[3]=r0; break;
    case WO_4_BADC: out[0]=r1; out[1]=r0; out[2]=r3; out[3]=r2; break;
    case WO_4_CDAB: out[0]=r2; out[1]=r3; out[2]=r0; out[3]=r1; break;
    }
}

/* Build big-endian byte stream from ordered 16-bit words */
static void words_to_bytes_be(const uint16_t w[], int nwords, uint8_t bytes[])
{
    for (int i = 0; i < nwords; i++) {
        bytes[2*i + 0] = (uint8_t)(w[i] >> 8);
        bytes[2*i + 1] = (uint8_t)(w[i] & 0xFF);
    }
}

static float bytes_be_to_float_host(const uint8_t be[4])
{
    uint8_t b[4];
    if (host_is_little_endian()) {
        b[0]=be[3]; b[1]=be[2]; b[2]=be[1]; b[3]=be[0];
    } else {
        memcpy(b, be, 4);
    }
    float f;
    memcpy(&f, b, 4);
    return f;
}

static double bytes_be_to_double_host(const uint8_t be[8])
{
    uint8_t b[8];
    if (host_is_little_endian()) {
        for (int i = 0; i < 8; i++) b[i] = be[7 - i];
    } else {
        memcpy(b, be, 8);
    }
    double d;
    memcpy(&d, b, 8);
    return d;
}

static double decode_point_value(const pointdef_t* p, const modbus_mapping_t* mb)
{
    if (!p || !mb) return 0.0;

    uint16_t a0 = addr_wire0(p);

    if (p->area == AREA_COIL) {
        int bit = (mb->tab_bits && mb->nb_bits > a0) ? (mb->tab_bits[a0] ? 1 : 0) : 0;
        return (double)bit;
    }

    const uint16_t* tab = NULL;
    int tab_len = 0;

    if (p->area == AREA_HR) { tab = mb->tab_registers; tab_len = mb->nb_registers; }
    else if (p->area == AREA_IR) { tab = mb->tab_input_registers; tab_len = mb->nb_input_registers; }
    else return 0.0;

    int w = enc_words(p->enc);
    if (!tab || (int)a0 + w > tab_len) return 0.0;

    if (p->enc == ENC_SINGLE) {
        uint16_t r0 = maybe_swap_bytes16(tab[a0+0], p->byte_swap);
        uint16_t r1 = maybe_swap_bytes16(tab[a0+1], p->byte_swap);

        uint16_t ow[2];
        reorder2(r0, r1, p->wo2, ow);

        uint8_t be[4];
        words_to_bytes_be(ow, 2, be);

        return (double)bytes_be_to_float_host(be);
    }

    if (p->enc == ENC_DOUBLE) {
        uint16_t r0 = maybe_swap_bytes16(tab[a0+0], p->byte_swap);
        uint16_t r1 = maybe_swap_bytes16(tab[a0+1], p->byte_swap);
        uint16_t r2 = maybe_swap_bytes16(tab[a0+2], p->byte_swap);
        uint16_t r3 = maybe_swap_bytes16(tab[a0+3], p->byte_swap);

        uint16_t ow[4];
        reorder4(r0, r1, r2, r3, p->wo4, ow);

        uint8_t be[8];
        words_to_bytes_be(ow, 4, be);

        return bytes_be_to_double_host(be);
    }

    /* integers (treat as MSW-first big-endian word order in registers) */
    uint64_t u = 0;
    for (int k = 0; k < w; k++)
        u = (u << 16) | (uint64_t)(tab[a0 + (uint16_t)k] & 0xFFFF);

    if (p->enc == ENC_INT16)  return (double)(int16_t)(u & 0xFFFF);
    if (p->enc == ENC_UINT16) return (double)(uint16_t)(u & 0xFFFF);
    if (p->enc == ENC_INT32)  return (double)(int32_t)(u & 0xFFFFFFFFu);
    if (p->enc == ENC_UINT32) return (double)(uint32_t)(u & 0xFFFFFFFFu);
    if (p->enc == ENC_INT64)  return (double)(int64_t)u;
    if (p->enc == ENC_UINT64) return (double)u;

    return (double)u;
}

void print_device_state(const devmap_t* dev, const modbus_mapping_t* mb)
{
    if (!dev || !mb) return;

    printf("\n=== DEVICE STATE ===\n");
    printf("unit_id=%d  device=%s\n", dev->unit_id, dev->device_name);
    printf("--------------------\n");

    for (int i = 0; i < dev->point_count; i++) {
        const pointdef_t* p = &dev->points[i];

        const char* area =
            (p->area == AREA_COIL)    ? "COIL" :
            (p->area == AREA_DISC_IN) ? "DISC_IN" :
            (p->area == AREA_HR)      ? "HR" :
            (p->area == AREA_IR)      ? "IR" : "UNK";

        double val = decode_point_value(p, mb);
        double eng = val * (double)p->scale;

#if PRINT_RAW_WORDS
        if (p->area == AREA_HR && (p->enc == ENC_DOUBLE)) {
            uint16_t a0 = addr_wire0(p);
            printf("[%s sim=%u wire=%u] %-20s raw=[%04X %04X %04X %04X]  wo4=%d bs=%d  val=%.9e (%.9e %s)\n",
                   area, (unsigned)p->addr, (unsigned)a0, p->name,
                   mb->tab_registers[a0+0], mb->tab_registers[a0+1], mb->tab_registers[a0+2], mb->tab_registers[a0+3],
                   (int)p->wo4, (int)p->byte_swap,
                   val, eng, p->unit);
            continue;
        }
#endif

        printf("[%s sim=%u wire=%u] %-20s = %.9e (%.9e %s)\n",
               area,
               (unsigned)p->addr,
               (unsigned)addr_wire0(p),
               p->name,
               val,
               eng,
               p->unit);
    }

    printf("====================\n");
}
