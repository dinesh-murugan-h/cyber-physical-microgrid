#include <pthread.h>
#include "iedconnectionhandler.h"
#include "modbusconnectionhandler.h"
#include "hal_thread.h"

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

    while (true)
        Thread_sleep(1000);

    return 0;
}
