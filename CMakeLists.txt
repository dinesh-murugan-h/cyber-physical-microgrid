cmake_minimum_required(VERSION 3.18)
project(cyber_physical_microgrid LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

# =========================
# === Global Paths ========
# =========================
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(IEC61850_DIR ${SRC_DIR}/iec61850)
set(SCL_DIR ${SRC_DIR}/scl)

# =========================
# === libiec61850 ========
# =========================
find_library(IEC61850_LIB
    NAMES iec61850
    PATHS ${CMAKE_SOURCE_DIR}/libiec61850/build/src
    NO_DEFAULT_PATH
)
if (NOT IEC61850_LIB)
    message(FATAL_ERROR "libiec61850 not found! Please build libiec61850 first.")
endif()

set(IEC61850_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/libiec61850/src
    ${CMAKE_SOURCE_DIR}/libiec61850/src/iec61850/inc
    ${CMAKE_SOURCE_DIR}/libiec61850/src/common/inc
    ${CMAKE_SOURCE_DIR}/libiec61850/src/mms/inc
    ${CMAKE_SOURCE_DIR}/libiec61850/src/logging
    ${CMAKE_SOURCE_DIR}/libiec61850/hal/inc
)
message(STATUS "libiec61850 library: ${IEC61850_LIB}")

# =========================
# === libmodbus ==========
# =========================
find_library(MODBUS_LIB
    NAMES modbus
    PATHS ${CMAKE_SOURCE_DIR}/libmodbus/build/lib
    NO_DEFAULT_PATH
)
find_path(MODBUS_INCLUDE_DIR
    NAMES modbus.h
    PATHS ${CMAKE_SOURCE_DIR}/libmodbus/build/include/modbus
    NO_DEFAULT_PATH
)
if(NOT MODBUS_LIB)
    message(FATAL_ERROR "libmodbus not found! Expected in libmodbus/build/lib")
endif()
if(NOT MODBUS_INCLUDE_DIR)
    message(FATAL_ERROR "modbus headers not found! Expected in libmodbus/build/include/modbus")
endif()

message(STATUS "libmodbus library: ${MODBUS_LIB}")
message(STATUS "libmodbus include: ${MODBUS_INCLUDE_DIR}")

# =========================
# === Source Files ========
# =========================
set(SRC_FILES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/iedconnectionhandler.cpp
    ${SRC_DIR}/modbusconnectionhandler.cpp
   # ${SRC_DIR}/modbus/modbus_server.cpp

    # Pre-generated static models
    ${SRC_DIR}/scl/static_model_1.c
    ${SRC_DIR}/scl/static_model_2.c
    ${SRC_DIR}/scl/static_model_3.c
)

# =========================
# === Build Target ========
# =========================
add_executable(main_app ${SRC_FILES})

target_include_directories(main_app PRIVATE
    ${SRC_DIR}
    ${SRC_DIR}/scl  
    ${IEC61850_DIR}
    ${MODBUS_INCLUDE_DIR}
    ${IEC61850_INCLUDE_DIRS}
)

find_package(Threads REQUIRED)

target_link_libraries(main_app
    PRIVATE
        ${IEC61850_LIB}
        ${MODBUS_LIB}
        Threads::Threads
)

# =========================
# === Output Info ========
# =========================
message(STATUS "CMake configuration complete.")
message(STATUS "  IEC61850 include dirs: ${IEC61850_INCLUDE_DIRS}")
message(STATUS "  Modbus include dir: ${MODBUS_INCLUDE_DIR}")
message(STATUS "  Sources: ${SRC_FILES}")
