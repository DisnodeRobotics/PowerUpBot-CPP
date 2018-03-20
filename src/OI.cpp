#include "OI.h"
#include "Commands/LiftBinary.h"
#include "Commands/IntakeBinary.h"
#include "Commands/Intake/IntakeLock.h"
#include "Commands/ReleaseOnce.h"
OI::OI()
{
	driverJoyboyLeft.reset(new Joystick(0));
	driverJoyboyRight.reset(new Joystick(1));

	liftUpButton.reset(new JoystickButton(driverJoyboyRight.get(), 3));
	liftDownButton.reset(new JoystickButton(driverJoyboyRight.get(), 4));
	
	liftUpButton.get()->WhileHeld(new LiftBinary(true));
	liftDownButton.get()->WhileHeld(new LiftBinary(false));

	intakeInButton.reset(new JoystickButton(driverJoyboyLeft.get(), 1));
	intakeOutButton.reset(new JoystickButton(driverJoyboyLeft.get(), 2));

	intakeInButton.get()->WhenPressed(new IntakeLock(true));
	intakeOutButton.get()->WhenPressed(new IntakeLock(false));

	

	releaseButton.reset(new JoystickButton(driverJoyboyRight.get(), 5));
	releaseButton.get()->WhenPressed(new ReleaseOnce());
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