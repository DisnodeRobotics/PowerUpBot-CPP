#include "DriveJoystick.h"
#include <cmath>

DriveJoystick::DriveJoystick() :
	Command()
{
	Requires(Robot::drivetrain.get());
	//Requires(Robot::intake.get());
	leftPos = 0.0f;
	rightPos = 0.0f;
}
void DriveJoystick::Initialize()
{
	Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);

	RoboMap::sparkLift->Set(0);
}

void DriveJoystick::Execute()
{
	std::cout<<"Encoder: "<< RoboMap::encoderLift->Get() << std::endl;
	
	Robot::drivetrain->SetArcadeDrive(-Robot::oi->getDriverLeft()->GetY(), Robot::oi->getDriverRight()->GetX());
	double lift = -Robot::oi->getLiftJoystick()->GetY();

	if (lift < 0) {
		lift = lift * 0.25;
	}

	RoboMap::sparkLift->Set(lift);

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
