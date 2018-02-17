#include "OI.h"



OI::OI()
{
	driverJoyboy.reset(new Joystick(1));

}

OI::~OI()
{
}

std::shared_ptr<Joystick> OI::getDriver()
{
	return driverJoyboy;
}