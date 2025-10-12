#include <pthread.h>
#include "iedconnectionhandler.h"
#include "modbusconnectionhandler.h"
#include "hal_thread.h"
#include "modbusreader.h"

extern "C" {
#include "static_model_1.h"
#include "static_model_2.h"
#include "static_model_3.h"
}

int main() 
{
    pthread_setname_np(pthread_self(), "MainLoop");

    CIed ied1(&IED1_iedModel, 102, "IED1");
    CIed ied2(&IED2_iedModel, 103, "IED2");
    CIed ied3(&IED3_iedModel, 104, "IED3");

    if (!ied1.start() || !ied2.start() || !ied3.start())
        return -1;

    ModbusConnectionHandler modbusServer(1502);  // 502 needs root, so use 1502 for user mode
    if (!modbusServer.start()) {
        fprintf(stderr, "Failed to start Modbus server.\n");
        return -1;
    }    


    ModbusReader m_modbusReader(modbusServer);
   
   // 4. Main simulation loop
    while (true) {
        // Example 1: Read register 21 as INT16
        int16_t reg21_val = 0;
        if (m_modbusReader.readValue(21, ModbusDataType::INT16, &reg21_val)) {
            std::cout << "[MODBUS] Register 21 (INT16) = " << reg21_val << std::endl;
        } else {
            std::cerr << "[MODBUS] Failed to read register 21." << std::endl;
        }

        // Example 2: Optionally read another value, e.g. FLOAT from reg 30
        float reg30_float = 0.0f;
        if (m_modbusReader.readValue(30, ModbusDataType::FLOAT, &reg30_float)) {
            std::cout << "[MODBUS] Register 30 (FLOAT) = " << reg30_float << std::endl;
        }

        // Example 3: Update Modbus mapping manually if needed
        modbus_mapping_t* map = modbusServer.getMapping();
        if (map) {
            map->tab_registers[50] = (uint16_t)(reg21_val + 10);  // just an example
        }

        Thread_sleep(1000); // sleep 1s between reads
    }

    return 0;
}
