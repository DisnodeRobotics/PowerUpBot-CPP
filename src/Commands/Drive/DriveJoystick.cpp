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
	Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
}

void DriveJoystick::Execute()
{
	//std::cout<<"Encoder: "<< Robot::drivetrain->GetEncoderLDistance() << std::endl;
	
	Robot::drivetrain->SetArcadeDrive(-Robot::oi->getDriverLeft()->GetY(), Robot::oi->getDriverRight()->GetX());
}

bool DriveJoystick::IsFinished()
{
	return false;
}

void DriveJoystick::End()
{
	Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
}
void DriveJoystick::Interrupted()
{
	Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
	std::printf("Warning: DriveJoystick interrupted!\n");
}
