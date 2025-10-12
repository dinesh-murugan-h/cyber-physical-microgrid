#pragma once

#include "modbusconnectionhandler.h"
#include <cstdint>
#include <iostream>
#include <cstring>
#include <modbus.h>   // for modbus_get_* helpers

/*
 * Supported Modbus Data Types
 */
enum class ModbusDataType {
    INT16,
    UINT16,
    INT32,
    UINT32,
    FLOAT,     // single precision (4 bytes)
    DOUBLE     // double precision (8 bytes)
};

/*
 * ModbusReader
 * ------------
 * Provides generic reading of typed data from Modbus mapping.
 */
class ModbusReader {
public:
    explicit ModbusReader(ModbusConnectionHandler& handler);

    // Generic read function: reads based on specified type
    bool readValue(int startAddr, ModbusDataType type, void* outValue);

private:
    bool readRegisters(int startAddr, int count, uint16_t* buffer);

    ModbusConnectionHandler& m_modbusHandler;
};
