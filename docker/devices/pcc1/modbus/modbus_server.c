// docker/devices/pcc1/modbus/modbus_server.c

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
#include "process_image.h"
#include "modbus_server.h"

static volatile int running = 1;

static void sigint_handler(int sig)
{
    (void)sig;
    running = 0;
}

/* ---------- helpers ---------- */

static int max_addr_words_for_area(const devmap_t* dev, area_t area)
{
    int maxw = 0;
    for (int i = 0; i < dev->point_count; i++) {
        const pointdef_t* p = &dev->points[i];
        if (p->area != area) continue;

        int w = enc_words(p->enc);
        int a0 = (int)addr_wire0(p);
        int end = a0 + w;
        if (end > maxw) maxw = end;
    }
    return maxw;
}

static void init_mapping_from_regmap(const devmap_t* dev, modbus_mapping_t* mb)
{
    if (!dev || !mb) return;

    for (int i = 0; i < dev->point_count; i++) {
        const pointdef_t* p = &dev->points[i];
        uint16_t a0 = addr_wire0(p);

        if (p->area == AREA_COIL && mb->tab_bits && a0 < mb->nb_bits) {
            mb->tab_bits[a0] = (p->init_raw != 0) ? 1 : 0;
        }
        else if (p->area == AREA_HR && mb->tab_registers) {
            int w = enc_words(p->enc);
            if ((int)a0 + w <= mb->nb_registers) {
                /* init_raw is uint64, store MSW-first into registers */
                uint64_t u = p->init_raw;
                for (int k = w - 1; k >= 0; k--) {
                    mb->tab_registers[a0 + (uint16_t)k] = (uint16_t)(u & 0xFFFFu);
                    u >>= 16;
                }
            }
        }
        else if (p->area == AREA_IR && mb->tab_input_registers) {
            int w = enc_words(p->enc);
            if ((int)a0 + w <= mb->nb_input_registers) {
                uint64_t u = p->init_raw;
                for (int k = w - 1; k >= 0; k--) {
                    mb->tab_input_registers[a0 + (uint16_t)k] = (uint16_t)(u & 0xFFFFu);
                    u >>= 16;
                }
            }
        }
    }
}

/* -------------------------
   Validation (Simulink-safe)
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

/* Validate an aligned HR point write starting at wire_addr0. */
static int validate_hr_point_write(const devmap_t* dev,
                                   const uint8_t* req,
                                   uint16_t wire_addr0,
                                   uint16_t words_in_this_write,
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

    int w = enc_words(p->enc);

    if (words_in_this_write < (uint16_t)w) {
        modbus_reply_exception(ctx, req, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
        return -1;
    }

    return 0;
}

static int validate_write_request(const devmap_t* dev, const uint8_t* query, modbus_t* ctx)
{
    uint8_t fc = query[7];

    if (fc == MODBUS_FC_WRITE_SINGLE_COIL) {
        uint16_t addr = (uint16_t)((query[8] << 8) | query[9]);   /* wire addr0 */
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

    if (fc == MODBUS_FC_WRITE_MULTIPLE_COILS) {
        uint16_t addr = (uint16_t)((query[8] << 8) | query[9]);   /* wire addr0 */
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

    /* FC06: only allow 1-word points */
    if (fc == MODBUS_FC_WRITE_SINGLE_REGISTER) {
        uint16_t addr = (uint16_t)((query[8] << 8) | query[9]);   /* wire addr0 */

        const pointdef_t* p = find_point_by_wire(dev, AREA_HR, addr);
        if (!p) {
            modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS);
            return -1;
        }
        if (p->access != REG_RW) {
            modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS);
            return -1;
        }
        if (enc_words(p->enc) != 1) {
            modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
            return -1;
        }

        return 0;
    }

    /* FC16: step across points */
    if (fc == MODBUS_FC_WRITE_MULTIPLE_REGISTERS) {
        uint16_t addr = (uint16_t)((query[8] << 8) | query[9]);   /* wire addr0 */
        uint16_t qty  = (uint16_t)((query[10] << 8) | query[11]);
        uint8_t byte_count = query[12];

        if (qty == 0) {
            modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
            return -1;
        }

        if (byte_count < (uint8_t)(2 * qty)) {
            modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
            return -1;
        }

        uint16_t cur = addr;
        uint16_t remaining = qty;

        while (remaining > 0) {

            const pointdef_t* p = find_point_by_wire(dev, AREA_HR, cur);
            if (!p) {
                modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS);
                return -1;
            }

            int w = enc_words(p->enc);
            if (w <= 0) {
                modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
                return -1;
            }

            if (validate_hr_point_write(dev, query, cur, remaining, ctx) != 0)
                return -1;

            if (remaining < (uint16_t)w) {
                modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE);
                return -1;
            }

            cur = (uint16_t)(cur + (uint16_t)w);
            remaining = (uint16_t)(remaining - (uint16_t)w);
        }

        return 0;
    }

    return 0;
}

/* ---- public run() function ---- */

int modbus_server_run(int unit_id, const char* bind_ip, int port, process_image_t* out_pi)
{
    setvbuf(stdout, NULL, _IOLBF, 0);

    const devmap_t* dev = get_devmap();
    if (!dev) {
        fprintf(stderr, "get_devmap() returned NULL\n");
        return 2;
    }

    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigint_handler);

    modbus_t* ctx = modbus_new_tcp(bind_ip ? bind_ip : "0.0.0.0", port);
    if (!ctx) {
        perror("modbus_new_tcp");
        return 3;
    }

    modbus_set_debug(ctx, FALSE);
    modbus_set_response_timeout(ctx, 0, 500000);

    int listen_fd = modbus_tcp_listen(ctx, 1);
    if (listen_fd == -1) {
        perror("modbus_tcp_listen");
        modbus_free(ctx);
        return 4;
    }

    int nb_bits = max_addr_words_for_area(dev, AREA_COIL);
    int nb_hr   = max_addr_words_for_area(dev, AREA_HR);
    int nb_ir   = max_addr_words_for_area(dev, AREA_IR);

    modbus_mapping_t* mb = modbus_mapping_new(nb_bits, 0, nb_hr, nb_ir);
    if (!mb) {
        perror("modbus_mapping_new");
        close(listen_fd);
        modbus_free(ctx);
        return 5;
    }

    init_mapping_from_regmap(dev, mb);

    if (out_pi) {
        pi_init(out_pi, dev, mb);
    }

    printf("Modbus TCP server listening on %s:%d\n", bind_ip ? bind_ip : "0.0.0.0", port);
    printf("Device: unit_id=%d name=%s\n", unit_id, dev->device_name);
    print_device_points(dev);
    print_device_state(dev, mb);

    while (running) {

        int client_socket = modbus_tcp_accept(ctx, &listen_fd);
        if (client_socket == -1) {
            if (!running) break;
            continue;
        }

        modbus_t* cctx = modbus_new_tcp(NULL, port);
        if (!cctx) {
            perror("modbus_new_tcp(client)");
            close(client_socket);
            continue;
        }

        modbus_set_socket(cctx, client_socket);

        printf("Client connected (device=%s)\n", dev->device_name);

        uint8_t q[MODBUS_TCP_MAX_ADU_LENGTH];
        time_t last_print_client = 0;

        while (running) {
            int rc = modbus_receive(cctx, q);
            if (rc > 0) {

                if (out_pi) pi_lock(out_pi);

                if (validate_write_request(dev, q, cctx) == 0) {
                    if (modbus_reply(cctx, q, rc, mb) == -1) {
                        if (out_pi) pi_unlock(out_pi);
                        break;
                    }
                }

                if (out_pi) pi_unlock(out_pi);

                time_t now = time(NULL);
                if (now != last_print_client) {
                    last_print_client = now;
                    if (out_pi) pi_lock(out_pi);
                    print_device_state(dev, mb);
                    if (out_pi) pi_unlock(out_pi);
                }
            }
            else {
                break;
            }
        }

        close(client_socket);
        modbus_close(cctx);
        modbus_free(cctx);

        printf("Client disconnected (device=%s)\n", dev->device_name);
    }

    if (out_pi) {
        pi_destroy(out_pi);
    }

    modbus_mapping_free(mb);
    close(listen_fd);
    modbus_close(ctx);
    modbus_free(ctx);

    return 0;
}

/* ---- standalone main ONLY when building modbus-only container ---- */
#ifdef MODBUS_SERVER_STANDALONE
int main(int argc, char** argv)
{
    setvbuf(stdout, NULL, _IOLBF, 0);

    int unit_id = 1;
    if (argc >= 2) unit_id = atoi(argv[1]);

    process_image_t pi;
    return modbus_server_run(unit_id, "0.0.0.0", 502, &pi);
}
#endif
