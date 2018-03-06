#include "DriveJoystick.h"
#include <cmath>

DriveJoystick::DriveJoystick() :
	Command()
{
	Requires(Robot::drivetrain.get());

	leftPos = 0.0f;
	rightPos = 0.0f;
}
void DriveJoystick::Initialize()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
}

void DriveJoystick::Execute()
{
	Robot::drivetrain->SetTankDrive(-Robot::oi->getDriverLeft()->GetY(), -Robot::oi->getDriverRight()->GetY());
}

bool DriveJoystick::IsFinished()
{
	return false;
}

void DriveJoystick::End()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
}
void DriveJoystick::Interrupted()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
	std::printf("Warning: DriveJoystick interrupted!\n");
}
