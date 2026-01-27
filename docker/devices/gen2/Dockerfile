# docker/devices/gen2/Dockerfile
FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    cmake \
    pkg-config \
    automake autoconf libtool \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt

# ---------- libmodbus (build from your repo copy) ----------
COPY libmodbus /opt/libmodbus
RUN cd /opt/libmodbus && \
    ./autogen.sh && \
    ./configure --prefix=/usr/local && \
    make -j"$(nproc)" && \
    make install && \
    ldconfig

# ---------- libiec61850 (build+install headers/libs) ----------
COPY libiec61850 /opt/libiec61850
RUN cd /opt/libiec61850 && \
    rm -rf build && mkdir -p build && cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local && \
    make -j"$(nproc)" && \
    make install && \
    ldconfig

# ---------- app sources ----------
WORKDIR /app
COPY docker/devices/gen2 /app/gen2


# Build ONE combined binary
WORKDIR /app/gen2

RUN gcc -O2 -Wall -Wextra \
  -DMODBUS_SERVER_EMBEDDED=1 \
  -I/app/gen2 \
  -I/app/gen2/modbus \
  -I/app/gen2/ied/model \
  -I/usr/local/include \
  -I/usr/local/include/libiec61850 \
  -o /usr/local/bin/gen2_device \
  /app/gen2/device_main.c \
  /app/gen2/modbus/modbus_server.c \
  /app/gen2/modbus/printmap.c \
  /app/gen2/ied/ied_server.c \
  /app/gen2/ied/model/static_model.c \
  -L/usr/local/lib \
  -liec61850 -lmodbus -lpthread -lm

EXPOSE 502 102
CMD ["/usr/local/bin/gen2_device"]
