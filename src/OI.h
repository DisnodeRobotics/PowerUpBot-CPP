#pragma once
#include "WPILib.h"
#include <memory>
class OI
{
private:
	std::shared_ptr<Joystick> driverJoyboy;
	std::shared_ptr<JoystickButton> liftUpButton;
	std::shared_ptr<JoystickButton> liftDownButton;
	std::shared_ptr<JoystickButton> intakeInButton;
	std::shared_ptr<JoystickButton> intakeOutButton;
	std::shared_ptr<JoystickButton> intakeLockButton;
	std::shared_ptr<JoystickButton> releaseButton;

	
public:
	OI();
	std::shared_ptr<Joystick> getDriver();
	~OI();
};

