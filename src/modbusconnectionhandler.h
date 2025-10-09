#pragma once

#include <modbus.h>
#include <thread>
#include <atomic>
#include <string>
#include <iostream>

class ModbusConnectionHandler {
public:
    ModbusConnectionHandler(int port, const std::string& ip = "0.0.0.0");
    ~ModbusConnectionHandler();

    bool start();
    void stop();

    modbus_t* getContext() const { return ctx_; }
    modbus_mapping_t* getMapping() const { return mapping_; }

private:
    void serverLoop();

    modbus_t* ctx_;
    modbus_mapping_t* mapping_;
    int serverSocket_;
    int port_;
    std::string ip_;
    std::thread serverThread_;
    std::atomic<bool> running_;
};
