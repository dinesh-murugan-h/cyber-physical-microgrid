#pragma once

#include "modbusconnectionhandler.h"
#include <cstdint>
#include <iostream>
#include <cstring>

/*
 * ModbusReader
 * ------------
 * Provides methods to read data (integers and doubles)
 * directly from the Modbus mapping of the running server.
 */
class ModbusReader {
public:
    explicit ModbusReader(ModbusConnectionHandler& handler);

    // Read one 16-bit register
    bool readRegister(int regAddr, uint16_t& value);

    // Read multiple consecutive registers
    bool readRegisters(int startAddr, int count, uint16_t* buffer);

    // Read an IEEE754 double (64-bit) from 4 consecutive registers
    double readDouble(int startAddr);

private:
    ModbusConnectionHandler& m_modbusHandler;
};
