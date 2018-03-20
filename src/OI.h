#pragma once
#include "WPILib.h"
#include <memory>
class OI
{
private:
	std::shared_ptr<Joystick> driverJoyboyLeft;
	std::shared_ptr<Joystick> driverJoyboyRight;
	std::shared_ptr<JoystickButton> liftUpButton;
	std::shared_ptr<JoystickButton> liftDownButton;

	std::shared_ptr<JoystickButton> intakeInButton;
	std::shared_ptr<JoystickButton> intakeOutButton;

	std::shared_ptr<JoystickButton> intakeLockButton;
	std::shared_ptr<JoystickButton> intakeUnlockButton;

	std::shared_ptr<JoystickButton> intakeDeployButton;
	std::shared_ptr<JoystickButton> intakeFoldButton;



	
public:
	OI();
	std::shared_ptr<Joystick> getDriverLeft();
	std::shared_ptr<Joystick> getDriverRight();
	~OI();
};

