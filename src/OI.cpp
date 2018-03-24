#include "OI.h"

#include "Commands/Intake/IntakeWheel.h"
#include "Commands/Intake/IntakeLock.h"
#include "Commands/Intake/IntakeDeploy.h"

OI::OI()
{
	driverJoyboyLeft.reset(new Joystick(0));
	driverJoyboyRight.reset(new Joystick(1));
	liftJoyboy.reset(new Joystick(2));

	liftUpButton.reset(new JoystickButton(driverJoyboyLeft.get(), 3));
	liftDownButton.reset(new JoystickButton(driverJoyboyLeft.get(), 4));


	//Intake
	intakeInButton.reset(new JoystickButton(driverJoyboyRight.get(), 1));
	intakeOutButton.reset(new JoystickButton(driverJoyboyRight.get(), 2));

	intakeInButton.get()->WhileHeld(new IntakeWheel(1.0));
	intakeOutButton.get()->WhileHeld(new IntakeWheel (-1));

	intakeLockButton.reset(new JoystickButton(driverJoyboyRight.get(), 3));
	intakeUnlockButton.reset(new JoystickButton(driverJoyboyRight.get(), 4));

	intakeLockButton.get()->WhenPressed(new IntakeLock(true));
	intakeUnlockButton.get()->WhenPressed(new IntakeLock(false));

	intakeDeployButton.reset(new JoystickButton(liftJoyboy.get(), 2));
	intakeFoldButton.reset(new JoystickButton(liftJoyboy.get(), 3));

	intakeDeployButton.get()->WhenPressed(new IntakeDeploy(false));
	intakeFoldButton.get()->WhenPressed(new IntakeDeploy(true));
	

}

OI::~OI()
{
}

std::shared_ptr<Joystick> OI::getDriverLeft()
{
	return driverJoyboyLeft;
}

std::shared_ptr<Joystick> OI::getDriverRight()
{
	return driverJoyboyRight;
}

std::shared_ptr<Joystick> OI::getLiftJoystick()
{
	return liftJoyboy;
}