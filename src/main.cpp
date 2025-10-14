#include <pthread.h>
#include "iedconnectionhandler.h"
#include "modbusconnectionhandler.h"
#include "hal_thread.h"
#include "modbusreader.h"
#include "modbustoiedtransfer.h"

extern "C" {
#include "static_model_1.h"
#include "static_model_2.h"
#include "static_model_3.h"
#include "gen1_static_model.h"
}

int main() 
{
    pthread_setname_np(pthread_self(), "MainLoop");

    CIed ied1(&IED1_iedModel, 102, "IED1");
    CIed gen1(&GEN1_iedModel, 103, "GEN1");

    if (!ied1.start() || !gen1.start())
        return -1;

    ModbusConnectionHandler modbusServer(1502);
    if (!modbusServer.start()) {
        fprintf(stderr, "Failed to start Modbus server.\n");
        return -1;
    }    

    ModbusReader m_modbusReader(modbusServer);
    ModbusToIEDTransfer bridge(m_modbusReader, gen1.getServer());

    while (true) {
        bridge.updateIEDFromModbus();  // reads Modbus, updates IED
        Thread_sleep(1000); // sleep 1s between reads
    }

    return 0;
}
