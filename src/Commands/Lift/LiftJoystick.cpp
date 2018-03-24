#include "LiftJoystick.h"
#include <cmath>

LiftJoystick::LiftJoystick() :
	Command()
{
	Requires(Robot::lift.get());
	
	
}
void LiftJoystick::Initialize()
{

}

void LiftJoystick::Execute()
{
	double joyVal = -Robot::oi->getLiftJoystick()->GetY();

	if (joyVal < 0) {
		joyVal = joyVal * 0.5;
	}
	Robot::lift->SetPower(joyVal);

}

bool LiftJoystick::IsFinished()
{
	return false;
}

void LiftJoystick::End()
{
	Robot::lift->SetPower(0);
}
void LiftJoystick::Interrupted()
{
	Robot::lift->SetPower(0);
	std::printf("Warning: DriveJoystick interrupted!\n");
}
