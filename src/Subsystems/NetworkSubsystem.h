#pragma once
#include "Commands/Subsystem.h"

#include "WPILib.h"
class NetworkSubsystem : Subsystem
{
private: 
	std::string networkName;
	Mode currentMode = Mode::TRANSMIT;
public:
	enum Mode {RECIEVE, TRANSMIT};
	
	
	


	NetworkSubsystem(std::string system_name, std::string network_name, NetworkSubsystem::Mode mode);

	virtual std::string GetStatus() {};
	virtual void SetStatus(std::string data[]) {};
	
	virtual void PIDDisable() {};
	virtual void PIDEnable() {};

	void SendStatus(std::string status);
};

