#pragma once
#include "Commands/Subsystem.h"
#include "RobotDrive.h"
#include "WPILib.h"
class Drivetrain : public Subsystem
{
private:
	std::shared_ptr<Spark> Spark1;
	std::shared_ptr<Spark> Spark2;
	std::shared_ptr<Spark> Spark3;
	std::shared_ptr<Spark> Spark4;
	std::shared_ptr<RobotDrive> robotDrive;
	std::shared_ptr<Encoder> encoderL;
	std::shared_ptr<Encoder> encoderR;
public:
	Drivetrain();
};

