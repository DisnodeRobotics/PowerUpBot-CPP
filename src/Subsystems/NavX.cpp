#include "NavX.h"
#include <stdio.h>

#include "RoboMap.h"

NavX::NavX() : NetworkSubsystem("NavX", "navx", NetworkSubsystem::TRANSMIT)
{
	hardware = RoboMap::navX.get();
}

double NavX::GetHeading()
{
	return hardware->GetFusedHeading();
}

std::string NavX::GetStatus()
{
	bool isConnected = hardware->IsConnected();
	double heading = hardware->GetFusedHeading();
	return std::toString(isConnected) + ";" + std::to_string(heading) + ";";

}


NavX::~NavX()
{
	delete hardware;
}
