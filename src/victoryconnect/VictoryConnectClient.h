#pragma once
#define PORT = 9000
#include <iostream>
#include "tcp/TCPClient.h"
#include <signal.h>
#include <thread>
#include <string.h>
#include <vector>
#include "Subsystems/NetworkSubsystem.h"
#include "../logging/Logger.h"
using namespace std;

class VictoryConnectClient
{
  private:
	 
    TCPClient *tcpClient;
   
    bool connected = false;
    void sig_exit(int s)
    {
        tcpClient->exit();
        exit(0);
    }
    static void recv_loop(TCPClient *client);

	static void tick_loop(TCPClient *client, std::vector<std::shared_ptr<NetworkSubsystem>> *systems);
	std::vector<std::shared_ptr<NetworkSubsystem>> subsystems;
  public:

    VictoryConnectClient();
	void AddSubsystem(std::shared_ptr<NetworkSubsystem> system);
    bool Connect(string host);
    bool SendPacket(int type, string topic, string value);
    bool isConnected();
};
