#pragma once
#include <AHRS.h>
#include "NetworkSubsystem.h"
#include <WPILib.h>
class NavX : NetworkSubsystem
{
private: 
	AHRS *hardware;

	
public:
	NavX();
	double GetHeading();
	std::string GetStatus();
	~NavX();
};
