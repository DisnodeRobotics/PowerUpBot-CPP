#include "OI.h"
#include "Commands/LiftBinary.h"
#include "Commands/IntakeBinary.h"
#include "Commands/IntakeLock.h"
#include "Commands/ReleaseOnce.h"
OI::OI()
{
	driverJoyboyLeft.reset(new Joystick(0));
	driverJoyboyRight.reset(new Joystick(1));

	liftUpButton.reset(new JoystickButton(driverJoyboyRight.get(), 3));
	liftDownButton.reset(new JoystickButton(driverJoyboyRight.get(), 4));
	
	liftUpButton.get()->WhileHeld(new LiftBinary(true));
	liftDownButton.get()->WhileHeld(new LiftBinary(false));

	intakeInButton.reset(new JoystickButton(driverJoyboyRight.get(), 1));
	intakeOutButton.reset(new JoystickButton(driverJoyboyRight.get(), 2));

	intakeInButton.get()->WhileHeld(new IntakeBinary(true));
	intakeOutButton.get()->WhileHeld(new IntakeBinary(false));

	intakeLockButton.reset(new JoystickButton(driverJoyboyRight.get(), 5));
	intakeLockButton.get()->ToggleWhenPressed(new IntakeLock());

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