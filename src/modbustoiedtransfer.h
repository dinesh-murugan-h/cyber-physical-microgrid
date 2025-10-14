#ifndef MODBUS_TO_IED_TRANSFER_H
#define MODBUS_TO_IED_TRANSFER_H

#include <iostream>
#include <cstdint>
#include "modbusreader.h"

extern "C" {
#include "gen1_static_model.h"
#include <iec61850_server.h>
}

#include <string>

class ModbusToIEDTransfer {
public:
    ModbusToIEDTransfer(ModbusReader& reader, IedServer server);
    void updateIEDFromModbus();

private:
    ModbusReader& m_reader;
    IedServer m_server;   // FIXED: store by value (pointer), not reference

    void updateVoltagePhases();
};

#endif // MODBUS_TO_IED_TRANSFER_H
