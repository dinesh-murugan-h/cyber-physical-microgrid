# docker/devices/pv/Dockerfile
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
COPY docker/devices/pv /app/pv


# Build ONE combined binary
WORKDIR /app/pv

RUN gcc -O2 -Wall -Wextra \
  -DMODBUS_SERVER_EMBEDDED=1 \
  -I/app/pv \
  -I/app/pv/modbus \
  -I/app/pv/ied/model \
  -I/usr/local/include \
  -I/usr/local/include/libiec61850 \
  -o /usr/local/bin/pv_device \
  /app/pv/device_main.c \
  /app/pv/modbus/modbus_server.c \
  /app/pv/modbus/printmap.c \
  /app/pv/ied/ied_server.c \
  /app/pv/ied/model/static_model.c \
  -L/usr/local/lib \
  -liec61850 -lmodbus -lpthread -lm

EXPOSE 502 102
CMD ["/usr/local/bin/pv_device"]
