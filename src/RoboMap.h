#pragma once
#include "WPILib.h"
#include "Ports.h"
#include "AHRS.h"
class RoboMap
{
public:
	static std::shared_ptr<Spark> sparkDriveLF;
	static std::shared_ptr<Spark> sparkDriveLR;
	static std::shared_ptr<Spark> sparkDriveRF;
	static std::shared_ptr<Spark> sparkDriveRR;
	
	static std::shared_ptr<Spark> sparkClimbL;
	static std::shared_ptr<Spark> sparkClimbR;

	static std::shared_ptr<Spark> sparkIntakeL;
	static std::shared_ptr<Spark> sparkIntakeR;

	static std::shared_ptr<Spark> sparkLift;

	static std::shared_ptr<DoubleSolenoid> solenoidPlatform1;
	static std::shared_ptr<DoubleSolenoid> solenoidPlatform2;
	static std::shared_ptr<DoubleSolenoid> solenoidPlatform3;
	static std::shared_ptr<DoubleSolenoid> solenoidPlatform4;

	//Sensors
	static std::shared_ptr<AHRS> navX;

	static std::shared_ptr<Ultrasonic> ultraFront;
	static std::shared_ptr<AnalogInput> ultraBottomL;
	static std::shared_ptr<AnalogInput> ultraBottomR;

	static std::shared_ptr<Encoder> encoderLeft;
	static std::shared_ptr<Encoder> encoderRight;

	//Software

	static void Init();
};

