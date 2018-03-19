#include "NetworkSubsystem.h"


NetworkSubsystem::NetworkSubsystem(std::string system_name, std::string network_name, NetworkSubsystem::Mode mode) : Subsystem(system_name)
{
	networkName = network_name;
	currentMode = mode;
}

NetworkSubsystem::~NetworkSubsystem()
{
}


void NetworkSubsystem::SendStatus(std::string status)
{
	// Sending VC Data;
}
