#include "iedconnectionhandler.h"
#include <iostream>
#include <cstdio>

CIed::CIed(IedModel* model, int port, const std::string& name)
  : model_(model), port_(port), name_(name)
{
    server_ = IedServer_create(model_);
    IedServer_setConnectionIndicationHandler(server_, connectionHandler, this);
}

CIed::~CIed()
{
    IedServer_stop(server_);
    IedServer_destroy(server_);
}

bool CIed::start()
{
    IedServer_start(server_, port_);
    if (!IedServer_isRunning(server_)) {
        std::cerr << "IED " << name_ << " failed to start on port " << port_ << "\n";
        return false;
    }

    std::cout << name_ << " running on port " << port_ << "\n";
    return true;
}

void CIed::stop()
{
    IedServer_stop(server_);
}

void CIed::connectionHandler(IedServer self,
                                       ClientConnection connection,
                                       bool connected,
                                       void* parameter)
{
    (void)self;
    (void)connection;
    CIed* instance = static_cast<CIed*>(parameter);
    if (instance)
        instance->onConnectionChanged(connected);
}

void CIed::onConnectionChanged(bool connected)
{
    std::cout << name_<< "client " 
              << (connected ? "connected" : "disconnected")
              << " to " << name_ 
              << " (port " << port_ << ")"
              << std::endl;
}
