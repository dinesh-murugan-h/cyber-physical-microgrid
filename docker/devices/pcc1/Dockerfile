
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


COPY libmodbus /opt/libmodbus
RUN cd /opt/libmodbus && \
    ./autogen.sh && \
    ./configure --prefix=/usr/local && \
    make -j"$(nproc)" && \
    make install && \
    ldconfig


COPY libiec61850 /opt/libiec61850
RUN cd /opt/libiec61850 && \
    rm -rf build && mkdir -p build && cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local && \
    make -j"$(nproc)" && \
    make install && \
    ldconfig


WORKDIR /app
COPY docker/devices/pcc1 /app/pcc1


WORKDIR /app/pcc1

RUN gcc -O2 -Wall -Wextra \
  -DMODBUS_SERVER_EMBEDDED=1 \
  -I/app/pcc1 \
  -I/app/pcc1/modbus \
  -I/app/pcc1/ied/model \
  -I/usr/local/include \
  -I/usr/local/include/libiec61850 \
  -o /usr/local/bin/pcc1_device \
  /app/pcc1/device_main.c \
  /app/pcc1/modbus/modbus_server.c \
  /app/pcc1/modbus/printmap.c \
  /app/pcc1/ied/ied_server.c \
  /app/pcc1/ied/model/static_model.c \
  -L/usr/local/lib \
  -liec61850 -lmodbus -lpthread -lm

EXPOSE 502 102
CMD ["/usr/local/bin/pcc1_device"]
