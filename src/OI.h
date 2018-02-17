#pragma once
#include "WPILib.h"

class OI
{
private:
	std::shared_ptr<Joystick> driverJoyboy;
public:
	OI();
	std::shared_ptr<Joystick> getDriver();
	~OI();
};

