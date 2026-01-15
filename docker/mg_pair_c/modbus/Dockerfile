# docker/mg_pair_c/modbus/Dockerfile

FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential automake autoconf libtool pkg-config \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt

# Expects your repo has ./libmodbus folder at the repo root
COPY libmodbus /opt/libmodbus

RUN cd /opt/libmodbus && \
    ./autogen.sh && \
    ./configure --prefix=/usr/local && \
    make -j && \
    make install && \
    ldconfig

WORKDIR /app

# Copy source
COPY docker/mg_pair_c/modbus/ /app/

# Compile + link
RUN gcc -O2 -Wall -Wextra \
    -I/app \
    -o /usr/local/bin/modbus_server \
    /app/modbus_server.c \
    /app/printmap.c \
    -lmodbus

EXPOSE 502
ENTRYPOINT ["/usr/local/bin/modbus_server"]
