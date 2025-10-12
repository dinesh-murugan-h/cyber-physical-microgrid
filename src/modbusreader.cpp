#include "modbusreader.h"

ModbusReader::ModbusReader(ModbusConnectionHandler& handler)
    : m_modbusHandler(handler) {}

/*
 * Internal helper to read multiple consecutive registers
 */
bool ModbusReader::readRegisters(int startAddr, int count, uint16_t* buffer)
{
    modbus_mapping_t* m_map = m_modbusHandler.getMapping();
    if (!m_map) return false;

    if (startAddr < 0 || (startAddr + count) > m_map->nb_registers) {
        std::cerr << "[ModbusReader] Invalid register range.\n";
        return false;
    }

    for (int i = 0; i < count; ++i)
        buffer[i] = m_map->tab_registers[startAddr + i];

    return true;
}

/*
 * Generic typed read function
 */
bool ModbusReader::readValue(int startAddr, ModbusDataType type, void* outValue)
{
    modbus_mapping_t* m_map = m_modbusHandler.getMapping();
    if (!m_map || !outValue) return false;

    uint16_t regs[4] = {0};

    switch (type) {

    case ModbusDataType::INT16: {
        if (!readRegisters(startAddr, 1, regs)) return false;
        int16_t val = static_cast<int16_t>(regs[0]);
        std::memcpy(outValue, &val, sizeof(val));
        break;
    }

    case ModbusDataType::UINT16: {
        if (!readRegisters(startAddr, 1, regs)) return false;
        uint16_t val = regs[0];
        std::memcpy(outValue, &val, sizeof(val));
        break;
    }

    case ModbusDataType::INT32: {
        if (!readRegisters(startAddr, 2, regs)) return false;
        int32_t val = ((int32_t)regs[0] << 16) | (int32_t)regs[1];
        std::memcpy(outValue, &val, sizeof(val));
        break;
    }

    case ModbusDataType::UINT32: {
        if (!readRegisters(startAddr, 2, regs)) return false;
        uint32_t val = ((uint32_t)regs[0] << 16) | (uint32_t)regs[1];
        std::memcpy(outValue, &val, sizeof(val));
        break;
    }

    case ModbusDataType::FLOAT: {
        if (!readRegisters(startAddr, 2, regs)) return false;
        float val = modbus_get_float_cdab(regs);  // CDAB = standard float order
        std::memcpy(outValue, &val, sizeof(val));
        break;
    }

    case ModbusDataType::DOUBLE: {
        if (!readRegisters(startAddr, 4, regs)) return false;
        uint64_t raw = ((uint64_t)regs[0] << 48) |
                       ((uint64_t)regs[1] << 32) |
                       ((uint64_t)regs[2] << 16) |
                       (uint64_t)regs[3];
        double val;
        std::memcpy(&val, &raw, sizeof(val));
        std::memcpy(outValue, &val, sizeof(val));
        break;
    }

    default:
        std::cerr << "[ModbusReader] Unsupported data type.\n";
        return false;
    }

    return true;
}
