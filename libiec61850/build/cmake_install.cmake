# Install script for directory: /home/dinesh/Documents/cyber-physical-microgrid/libiec61850

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libiec61850" TYPE FILE FILES
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/hal/inc/hal_base.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/hal/inc/hal_time.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/hal/inc/hal_thread.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/hal/inc/hal_filesystem.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/hal/inc/hal_ethernet.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/hal/inc/hal_socket.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/hal/inc/tls_config.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/hal/inc/tls_ciphers.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/common/inc/libiec61850_common_api.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/common/inc/linked_list.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/common/inc/sntp_client.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/iec61850/inc/iec61850_client.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/iec61850/inc/iec61850_common.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/iec61850/inc/iec61850_server.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/iec61850/inc/iec61850_model.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/iec61850/inc/iec61850_cdc.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/iec61850/inc/iec61850_dynamic_model.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/iec61850/inc/iec61850_config_file_parser.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/mms/inc/mms_value.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/mms/inc/mms_common.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/mms/inc/mms_types.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/mms/inc/mms_type_spec.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/mms/inc/mms_client_connection.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/mms/inc/mms_server.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/mms/inc/iso_connection_parameters.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/goose/goose_subscriber.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/goose/goose_receiver.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/goose/goose_publisher.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/sampled_values/sv_subscriber.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/sampled_values/sv_publisher.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/r_session/r_session.h"
    "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/src/logging/logging_api.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/build/hal/cmake_install.cmake")
  include("/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/build/examples/cmake_install.cmake")
  include("/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/build/src/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/dinesh/Documents/cyber-physical-microgrid/libiec61850/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
