#include "Drivetrain.h"
#include "../RoboMap.h"
#include "Commands/Drive/DriveJoystick.h"
Drivetrain::Drivetrain() :
	Subsystem("Drivetrain")
{
	Spark1 = RoboMap::sparkDriveLF;
	Spark1 = RoboMap::sparkDriveLR;
	Spark1 = RoboMap::sparkDriveRF;
	Spark1 = RoboMap::sparkDriveRR;
	GroupL = RoboMap::sgroupDriveL;
	GroupL = RoboMap::sgroupDriveR;

	robotDrive = RoboMap::robotDrive;
	encoderL = RoboMap::encoderLeft;
	encoderR = RoboMap::encoderRight;
	robotDrive->SetSafetyEnabled(false);
}

void Drivetrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveJoystick());
}

void Drivetrain::SetTankDrive(float leftPower, float rightPower)
{
	robotDrive->TankDrive(leftPower, rightPower);
}

void Drivetrain::SetArcadeDrive(float movePower, float rotatePower)
{
	std::cout << GetEncoderRDistance() << std::endl;
	robotDrive->ArcadeDrive(movePower, rotatePower);
}

void Drivetrain::SetManualDrive(float outputPower, float curveSharpness)
{
	
}



void Drivetrain::Stop() {
	SetManualDrive(0, 0);
}



double Drivetrain::GetEncoderLDistance()
{
	return encoderL->Get() ; //this is so we can change this later
}

double Drivetrain::GetEncoderRDistance()
{
	return encoderR->Get() ;
}

double Drivetrain::GetAverageEncoderDistance()
{
	return ((this->GetEncoderLDistance()) + (this->GetEncoderRDistance())) / 2;
}

std::shared_ptr<Spark> Drivetrain::GetSpark(int id)
{
	switch (id)
	{
	case 1: return RoboMap::sparkDriveLF;
		break;
	case 2: return RoboMap::sparkDriveLR;
		break;
	case 3: return RoboMap::sparkDriveRF;
		break;
	case 4: return RoboMap::sparkDriveRR;
		break;
	default:
		printf("Spark ID out of range in Drivetrain::Spark");
		return 0;
		break;
	}
}