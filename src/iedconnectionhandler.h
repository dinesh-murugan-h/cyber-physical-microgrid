#pragma once

#include <string>

extern "C" {
#include <iec61850_server.h>
}

class CIed {
public:
  CIed(IedModel* model, int port, const std::string& name);
  ~CIed();

  bool start();
  void stop();

  IedServer getServer() const {
    return server_;
  }

private:
  static void connectionHandler(IedServer self,
                                ClientConnection connection,
                                bool connected,
                                void* parameter);

  void onConnectionChanged(bool connected);

  IedServer server_;
  IedModel* model_;
  int port_;
  std::string name_;
};
