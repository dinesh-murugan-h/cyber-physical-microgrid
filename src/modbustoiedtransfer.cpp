#include "modbustoiedtransfer.h"
#include "hal_thread.h"

ModbusToIEDTransfer::ModbusToIEDTransfer(ModbusReader& reader, IedServer server)
    : m_reader(reader), m_server(server) {}

void ModbusToIEDTransfer::updateIEDFromModbus() {
    if (!m_server) {
        std::cerr << "[ERROR] IED server handle is null, skipping update.\n";
        return;
    }
    updateVoltagePhases();
}

void ModbusToIEDTransfer::updateVoltagePhases() {
    const int startReg = 21;
    const int numRegs = 3;
    double voltage = 0.0;

    IedServer_lockDataModel(m_server);   // prevent race conditions

    for (int i = 0; i < numRegs; ++i) {
        int regAddr = startReg + i;

        if (m_reader.readValue(regAddr, ModbusDataType::DOUBLE, &voltage)) {
            std::cout << "[MODBUStoIED] Phase " << static_cast<char>('A' + i)
                      << " Voltage = " << voltage << std::endl;

            const DataAttribute* constAttr = nullptr;

            switch (i) {
                case 0:
                    constAttr = GEN1_IEDMODEL_GEN1_MMXU1_PhV_phsA_mag_f;
                    break;
                case 1:
                    constAttr = GEN1_IEDMODEL_GEN1_MMXU1_PhV_phsB_mag_f;
                    break;
                case 2:
                    constAttr = GEN1_IEDMODEL_GEN1_MMXU1_PhV_phsC_mag_f;
                    break;
            }

            // Cast away constness when passing to the API
            DataAttribute* attr = const_cast<DataAttribute*>(constAttr);

            // Write new value to IED model
            IedServer_updateFloatAttributeValue(m_server, attr, static_cast<float>(voltage));

            // Now read it back for verification
            float readBack = IedServer_getFloatAttributeValue(m_server, attr);

            std::cout << "   [READBACK] "
                      << static_cast<char>('A' + i)
                      << " stored in IED = " << readBack << " V"
                      << std::endl;
        }
    }

    IedServer_unlockDataModel(m_server); // release lock
}

