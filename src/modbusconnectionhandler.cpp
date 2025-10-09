#include <pthread.h>
#include "modbusconnectionhandler.h"
#include <unistd.h>  // for close()

ModbusConnectionHandler::ModbusConnectionHandler(int port, const std::string& ip)
    : ctx_(nullptr), mapping_(nullptr), serverSocket_(-1),
      port_(port), ip_(ip), running_(false)
{
    ctx_ = modbus_new_tcp(ip_.c_str(), port_);
    if (!ctx_) {
        std::cerr << "Failed to create Modbus context: " << modbus_strerror(errno) << std::endl;
    }

    // Default mapping: 100 holding registers
    mapping_ = modbus_mapping_new(0, 0, 100, 0);
    if (!mapping_) {
        std::cerr << "Failed to create Modbus mapping: " << modbus_strerror(errno) << std::endl;
    }

    // Optional: initialize some registers
    for (int i = 0; i < 100; ++i)
        mapping_->tab_registers[i] = i;
}

ModbusConnectionHandler::~ModbusConnectionHandler() {
    stop();

    if (mapping_) {
        modbus_mapping_free(mapping_);
        mapping_ = nullptr;
    }

    if (ctx_) {
        modbus_free(ctx_);
        ctx_ = nullptr;
    }
}

bool ModbusConnectionHandler::start() {
    if (!ctx_ || !mapping_) {
        std::cerr << "Modbus server cannot start: invalid context or mapping.\n";
        return false;
    }

    serverSocket_ = modbus_tcp_listen(ctx_, 1);  // backlog 1
    if (serverSocket_ == -1) {
        std::cerr << "Failed to listen on port " << port_ << ": "
                  << modbus_strerror(errno) << std::endl;
        return false;
    }

    running_ = true;
    serverThread_ = std::thread(&ModbusConnectionHandler::serverLoop, this);

    std::cout << "Modbus server started on " << ip_ << ":" << port_ << std::endl;
    return true;
}

void ModbusConnectionHandler::stop() {
    if (running_) {
        running_ = false;
        if (serverThread_.joinable())
            serverThread_.join();

        if (serverSocket_ != -1) {
            close(serverSocket_);
            serverSocket_ = -1;
        }

        std::cout << "Modbus server stopped." << std::endl;
    }
}

void ModbusConnectionHandler::serverLoop() {
    pthread_setname_np(pthread_self(), "ModbusSrv");  // thread label
    int clientSocket = -1;
    uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];

    while (running_) {
        if (clientSocket == -1) {
            clientSocket = modbus_tcp_accept(ctx_, &serverSocket_);
            if (clientSocket != -1) {
                std::cout << "Modbus client connected." << std::endl;
            }
        }

        int rc = modbus_receive(ctx_, query);
        if (rc > 0) {
            // Valid Modbus request received
            modbus_reply(ctx_, query, rc, mapping_);
        }
        else if (rc == -1) {
            // Disconnected or error
            if (clientSocket != -1) {
                std::cout << "Modbus client disconnected." << std::endl;
                close(clientSocket);
                clientSocket = -1;
            }
        }
    }

    // Cleanup if still connected
    if (clientSocket != -1) {
        close(clientSocket);
        clientSocket = -1;
    }
}
