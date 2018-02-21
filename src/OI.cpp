#include "OI.h"
#include "Commands/LiftBinary.h"
#include "Commands/IntakeBinary.h"
#include "Commands/IntakeLock.h"
#include "Commands/ReleaseOnce.h"
OI::OI()
{
	driverJoyboy.reset(new Joystick(0));

	liftUpButton.reset(new JoystickButton(driverJoyboy.get(), 3));
	liftDownButton.reset(new JoystickButton(driverJoyboy.get(), 4));
	
	liftUpButton.get()->WhileHeld(new LiftBinary(true));
	liftDownButton.get()->WhileHeld(new LiftBinary(false));

	intakeInButton.reset(new JoystickButton(driverJoyboy.get(), 1));
	intakeOutButton.reset(new JoystickButton(driverJoyboy.get(), 2));

	intakeInButton.get()->WhileHeld(new IntakeBinary(true));
	intakeOutButton.get()->WhileHeld(new IntakeBinary(false));

	intakeLockButton.reset(new JoystickButton(driverJoyboy.get(), 5));
	intakeLockButton.get()->ToggleWhenPressed(new IntakeLock());

	releaseButton.reset(new JoystickButton(driverJoyboy.get(), 5));
	releaseButton.get()->WhenPressed(new ReleaseOnce());
}

OI::~OI()
{
}

std::shared_ptr<Joystick> OI::getDriver()
{
	return driverJoyboy;
}