cmake_minimum_required(VERSION 3.10)
project(capstone_server C)

set(CMAKE_C_STANDARD 11)

# Headers (point to root include dirs)
include_directories(
    ${CMAKE_SOURCE_DIR}/libiec61850/install/include/libiec61850
    ${CMAKE_SOURCE_DIR}/libmodbus/install/include/modbus
    ${CMAKE_SOURCE_DIR}/libiec61850/src/iec61850/inc_private
)

# Libraries
link_directories(
    ${CMAKE_SOURCE_DIR}/libiec61850/install/lib
    ${CMAKE_SOURCE_DIR}/libmodbus/install/lib
)

# Executable
add_executable(bridge_server
    src/bridge_server.c
    src/static_model.c   # needed for IEC 61850
)

# Link against libs
target_link_libraries(bridge_server
    iec61850
    modbus
    pthread
)
