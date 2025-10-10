#include "modbusreader.h"

ModbusReader::ModbusReader(ModbusConnectionHandler& handler)
    : m_modbusHandler(handler)
{
}

bool ModbusReader::readRegister(int regAddr, uint16_t& value)
{
    modbus_mapping_t* m_map = m_modbusHandler.getMapping();
    if (!m_map) return false;

    if (regAddr < 0 || regAddr >= m_map->nb_registers) {
        std::cerr << "[ModbusReader] Invalid register: " << regAddr << "\n";
        return false;
    }

    value = m_map->tab_registers[regAddr];
    return true;
}

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
 * Read an IEEE754 double (64-bit) from 4 consecutive Modbus registers.
 * Equivalent to legacy read_double_from_registers().
 */
double ModbusReader::readDouble(int startAddr)
{
    modbus_mapping_t* m_map = m_modbusHandler.getMapping();
    if (!m_map) return 0.0;

    if (startAddr < 0 || (startAddr + 3) >= m_map->nb_registers) {
        std::cerr << "[ModbusReader] Invalid double read starting at register "
                  << startAddr << "\n";
        return 0.0;
    }

    uint16_t regs[4];
    regs[0] = m_map->tab_registers[startAddr];
    regs[1] = m_map->tab_registers[startAddr + 1];
    regs[2] = m_map->tab_registers[startAddr + 2];
    regs[3] = m_map->tab_registers[startAddr + 3];

    // Combine 4 x 16-bit registers into 64-bit integer (big-endian)
    uint64_t raw = ((uint64_t)regs[0] << 48) |
                   ((uint64_t)regs[1] << 32) |
                   ((uint64_t)regs[2] << 16) |
                   (uint64_t)regs[3];

    double result;
    std::memcpy(&result, &raw, sizeof(double));

    return result;
}
