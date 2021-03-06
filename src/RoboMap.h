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


	static std::shared_ptr<Spark> sparkIntake;

	static std::shared_ptr<Spark> sparkLift;

	static std::shared_ptr<Servo> servoRelease;

	static std::shared_ptr<DoubleSolenoid> solenoidIntakeLock;
	static std::shared_ptr<DoubleSolenoid> solenoidIntakeDeploy;
	//Sensors
	static std::shared_ptr<AHRS> navX;

	static std::shared_ptr<Ultrasonic> ultraFront;
	static std::shared_ptr<AnalogInput> ultraBottomL;
	static std::shared_ptr<AnalogInput> ultraBottomR;

	static std::shared_ptr<Encoder> encoderLeft;
	static std::shared_ptr<Encoder> encoderRight;
	static std::shared_ptr<Encoder> encoderLift;

	//Software
	static std::shared_ptr<DifferentialDrive> robotDrive;
	static std::shared_ptr<SpeedControllerGroup> sgroupDriveL;
	static std::shared_ptr<SpeedControllerGroup> sgroupDriveR;

	static void Init();
};

