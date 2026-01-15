// docker/mg_pair_c/modbus/modbus_server.c
#include <modbus/modbus.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include "regmap.h"
#include "printmap.h"

static volatile sig_atomic_t running = 1;
static int listen_fd = -1;

static void on_sigint(int sig)
{
    (void)sig;
    running = 0;

    // Force unblock of modbus_tcp_accept()
    if (listen_fd != -1) {
        close(listen_fd);
        listen_fd = -1;
    }
}

/* -------------------------
   Helpers: find required mapping sizes from regmap
   ------------------------- */
typedef struct {
    int nb_coils;
    int nb_disc_inputs;
    int nb_holding_regs;
    int nb_input_regs;
} map_sizes_t;

static map_sizes_t compute_required_sizes(const devmap_t* dev)
{
    map_sizes_t s = {0, 0, 0, 0};

    for (int i = 0; i < dev->point_count; i++) {
        const pointdef_t* p = &dev->points[i];

        int words = 1;
        if (p->area == AREA_HR || p->area == AREA_IR)
            words = enc_words(p->enc);

        // mapping arrays are indexed with wire addr0 = (sim addr - 1)
        int base0 = (int)addr_wire0(p);
        int need = base0 + words;  // "count" = last_index+1

        switch (p->area) {
        case AREA_COIL:
            if (need > s.nb_coils) s.nb_coils = need;
            break;
        case AREA_DISC_IN:
            if (need > s.nb_disc_inputs) s.nb_disc_inputs = need;
            break;
        case AREA_HR:
            if (need > s.nb_holding_regs) s.nb_holding_regs = need;
            break;
        case AREA_IR:
            if (need > s.nb_input_regs) s.nb_input_regs = need;
            break;
        default:
            break;
        }
    }

    return s;
}

/* Initialize libmodbus mapping with init_raw values from regmap */
static void init_mapping_from_regmap(modbus_mapping_t* mb, const devmap_t* dev)
{
    for (int i = 0; i < dev->point_count; i++) {
        const pointdef_t* p = &dev->points[i];
        uint16_t a0 = addr_wire0(p);

        if (p->area == AREA_COIL) {
            if (mb->tab_bits && (int)a0 < mb->nb_bits)
                mb->tab_bits[a0] = (p->init_raw != 0) ? 1 : 0;
            continue;
        }

        if (p->area == AREA_DISC_IN) {
            if (mb->tab_input_bits && (int)a0 < mb->nb_input_bits)
                mb->tab_input_bits[a0] = (p->init_raw != 0) ? 1 : 0;
            continue;
        }

        // Holding / Input registers (16-bit words)
        uint16_t* tab = NULL;
        int tab_len = 0;

        if (p->area == AREA_HR) {
            tab = mb->tab_registers;
            tab_len = mb->nb_registers;
        }
        else if (p->area == AREA_IR) {
            tab = mb->tab_input_registers;
            tab_len = mb->nb_input_registers;
        }
        else {
            continue;
        }

        if (!tab) continue;

        int w = enc_words(p->enc);
        if ((int)a0 + w > tab_len) continue;

        uint64_t u = p->init_raw;

        // Store big-endian word order: [a0] gets the top word
        for (int k = 0; k < w; k++) {
            int shift = 16 * (w - 1 - k);
            tab[a0 + (uint16_t)k] = (uint16_t)((u >> shift) & 0xFFFF);
        }
    }
}

/* Print the device map at startup */
static void print_devmap(const devmap_t* dev)
{
    printf("Device: unit_id=%d name=%s\n", dev->unit_id, dev->device_name);
    printf("Points (Simulink addr is 1-based; wire/libmodbus index is addr-1):\n");

    for (int i = 0; i < dev->point_count; i++) {
        const pointdef_t* p = &dev->points[i];

        const char* area =
            (p->area == AREA_COIL) ? "COIL" :
            (p->area == AREA_DISC_IN) ? "DISC_IN" :
            (p->area == AREA_HR) ? "HOLDING_REG" :
            (p->area == AREA_IR) ? "INPUT_REG" : "UNKNOWN";

        const char* acc = (p->access == REG_RW) ? "RW" : "RO";

        printf("  %-20s area=%-11s sim_addr=%u wire=%u  %s  enc=%d  scale=%g %s\n",
               p->name,
               area,
               (unsigned)p->addr,
               (unsigned)addr_wire0(p),
               acc,
               (int)p->enc,
               p->scale,
               p->unit);
    }
}

/* -------------------------
   Validation
   ------------------------- */

static int validate_coil_write(const devmap_t* dev,
                               const uint8_t* req,
                               uint16_t wire_addr0,
                               int value,
                               modbus_t* ctx)
{
    const pointdef_t* p = find_point_by_wire(dev, AREA_COIL, wire_addr0);
    if (!p) {
        modbus_reply_exception(ctx, req, MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS);
        return -1;
    }
    if (p->access != REG_RW) {
        modbus_reply_exception(ctx, req, MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS);
        return -1;
    }
    if (!point_raw_in_range_i64(p, (int64_t)value)) {
        modbus_reply_exception(ctx, req, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
        return -1;
    }
    return 0;
}

static int validate_hr_write_word(const devmap_t* dev,
                                  const uint8_t* req,
                                  uint16_t wire_addr0,
                                  uint16_t word_value,
                                  modbus_t* ctx)
{
    const pointdef_t* p = find_point_by_wire(dev, AREA_HR, wire_addr0);
    if (!p) {
        modbus_reply_exception(ctx, req, MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS);
        return -1;
    }
    if (p->access != REG_RW) {
        modbus_reply_exception(ctx, req, MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS);
        return -1;
    }

    // For float types, skip integer range checking (range checks on words are meaningless)
    if (!enc_is_float(p->enc)) {
        if (!point_raw_in_range_i64(p, (int64_t)word_value)) {
            modbus_reply_exception(ctx, req, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
            return -1;
        }
    }

    return 0;
}

static int validate_write_request(const devmap_t* dev, const uint8_t* query, modbus_t* ctx)
{
    uint8_t fc = query[7];

    // FC05: Write Single Coil
    if (fc == MODBUS_FC_WRITE_SINGLE_COIL) {
        uint16_t addr = (uint16_t)((query[8] << 8) | query[9]);   // wire addr0
        uint16_t val  = (uint16_t)((query[10] << 8) | query[11]);

        int bit;
        if (val == 0xFF00) bit = 1;
        else if (val == 0x0000) bit = 0;
        else {
            modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
            return -1;
        }

        return validate_coil_write(dev, query, addr, bit, ctx);
    }

    // FC15: Write Multiple Coils
    if (fc == MODBUS_FC_WRITE_MULTIPLE_COILS) {
        uint16_t addr = (uint16_t)((query[8] << 8) | query[9]);   // wire addr0
        uint16_t qty  = (uint16_t)((query[10] << 8) | query[11]);
        uint8_t byte_count = query[12];
        const uint8_t* data = &query[13];

        uint16_t need_bytes = (uint16_t)((qty + 7) / 8);
        if (byte_count < need_bytes) {
            modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
            return -1;
        }

        for (uint16_t i = 0; i < qty; i++) {
            uint16_t a = (uint16_t)(addr + i);
            int bit = (data[i / 8] >> (i % 8)) & 0x01;
            if (validate_coil_write(dev, query, a, bit, ctx) != 0)
                return -1;
        }
        return 0;
    }

    // FC06: Write Single Register (1 word)
    if (fc == MODBUS_FC_WRITE_SINGLE_REGISTER) {
        uint16_t addr = (uint16_t)((query[8] << 8) | query[9]);   // wire addr0
        uint16_t val  = (uint16_t)((query[10] << 8) | query[11]);
        return validate_hr_write_word(dev, query, addr, val, ctx);
    }

    // FC16: Write Multiple Registers (qty words)
    if (fc == MODBUS_FC_WRITE_MULTIPLE_REGISTERS) {
        uint16_t addr = (uint16_t)((query[8] << 8) | query[9]);   // wire addr0
        uint16_t qty  = (uint16_t)((query[10] << 8) | query[11]);
        uint8_t byte_count = query[12];
        const uint8_t* data = &query[13];

        if (byte_count < (uint8_t)(2 * qty)) {
            modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
            return -1;
        }

        for (uint16_t i = 0; i < qty; i++) {
            uint16_t a = (uint16_t)(addr + i);
            uint16_t v = (uint16_t)((data[2*i] << 8) | data[2*i + 1]);
            if (validate_hr_write_word(dev, query, a, v, ctx) != 0)
                return -1;
        }
        return 0;
    }

    return 0;
}

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    int unit_id = 1;
    if (argc >= 2)
        unit_id = atoi(argv[1]);

    const devmap_t* dev = get_devmap(unit_id);
    if (!dev) {
        fprintf(stderr, "No device mapping for unit_id=%d. Add it to regmap.h DEVICES[].\n", unit_id);
        return 1;
    }

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = on_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    modbus_t *ctx = modbus_new_tcp("0.0.0.0", 502);
    if (!ctx) {
        perror("modbus_new_tcp");
        return 1;
    }

    modbus_set_slave(ctx, unit_id);

    listen_fd = modbus_tcp_listen(ctx, 1);
    if (listen_fd == -1) {
        perror("modbus_tcp_listen");
        modbus_free(ctx);
        return 1;
    }

    printf("Modbus TCP server listening on 0.0.0.0:502\n");
    print_devmap(dev);

    map_sizes_t sizes = compute_required_sizes(dev);

    modbus_mapping_t *mb = modbus_mapping_new(
        sizes.nb_coils,
        sizes.nb_disc_inputs,
        sizes.nb_holding_regs,
        sizes.nb_input_regs
    );

    if (!mb) {
        perror("modbus_mapping_new");
        close(listen_fd);
        modbus_free(ctx);
        return 1;
    }

    init_mapping_from_regmap(mb, dev);

    print_device_state(dev, mb);

    uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
    time_t last_print = 0;

    while (running) {
        int client_socket = modbus_tcp_accept(ctx, &listen_fd);
        if (client_socket == -1)
            break;

        printf("Client connected (unit_id=%d device=%s)\n", unit_id, dev->device_name);

        while (running) {
            int rc = modbus_receive(ctx, query);
            if (rc > 0) {

                if (validate_write_request(dev, query, ctx) != 0) {
                    continue; // exception already sent
                }

                if (modbus_reply(ctx, query, rc, mb) == -1)
                    break;

                time_t now = time(NULL);
                if (now != last_print) {
                    last_print = now;
                    print_device_state(dev, mb);
                }
            }
            else {
                break;
            }
        }

        close(client_socket);
        printf("Client disconnected (unit_id=%d)\n", unit_id);
    }

    printf("Modbus server stopping (unit_id=%d)\n", unit_id);

    modbus_mapping_free(mb);
    if (listen_fd != -1) close(listen_fd);
    modbus_close(ctx);
    modbus_free(ctx);

    return 0;
}
