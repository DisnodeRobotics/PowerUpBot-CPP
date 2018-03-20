#include "RoboMap.h"
#include <iostream>
std::shared_ptr<Spark> RoboMap::sparkDriveLF;
std::shared_ptr<Spark> RoboMap::sparkDriveLR;
std::shared_ptr<Spark> RoboMap::sparkDriveRF;
std::shared_ptr<Spark> RoboMap::sparkDriveRR;


std::shared_ptr<Spark> RoboMap::sparkIntake;


std::shared_ptr<Spark> RoboMap::sparkLift;
std::shared_ptr<Servo> RoboMap::servoRelease;

std::shared_ptr<DoubleSolenoid> RoboMap::solenoidIntakeLock;
std::shared_ptr<DoubleSolenoid> RoboMap::solenoidIntakeDeploy;

//Sensors
std::shared_ptr<AHRS> RoboMap::navX;

std::shared_ptr<Ultrasonic> RoboMap::ultraFront;
std::shared_ptr<AnalogInput> RoboMap::ultraBottomL;
std::shared_ptr<AnalogInput> RoboMap::ultraBottomR;

std::shared_ptr<Encoder> RoboMap::encoderLeft;
std::shared_ptr<Encoder> RoboMap::encoderRight;

//Software
std::shared_ptr<DifferentialDrive> RoboMap::robotDrive;
std::shared_ptr<SpeedControllerGroup> RoboMap::sgroupDriveL;
std::shared_ptr<SpeedControllerGroup> RoboMap::sgroupDriveR;


void RoboMap::Init()
{
	sparkDriveLF.reset(new Spark(PWMPorts::DRIVE_LEFT_FRONT));
	sparkDriveLR.reset(new Spark(PWMPorts::DRIVE_LEFT_REAR));
	sparkDriveRF.reset(new Spark(PWMPorts::DRIVE_RIGHT_FRONT));
	sparkDriveRR.reset(new Spark(PWMPorts::DRIVE_RIGHT_REAR));


	sparkIntake.reset(new Spark(PWMPorts::INTAKE));


	sparkLift.reset(new Spark(PWMPorts::LIFT));
	std::cout << "Init NavX..." << std::endl;
	navX.reset(new AHRS(SPI::Port::kMXP));
	std::cout << "Navx Connected: " << navX->IsConnected() << std::endl;
	std::cout << "Navx Error: " << navX->GetError().GetMessage() << std::endl;
	std::cout << "Init Encoders..." << std::endl;
	encoderLeft.reset(new Encoder(0, 1));
	encoderRight.reset(new Encoder(2, 3));
	std::cout << encoderLeft->GetGlobalError().GetMessage() << std::endl;
	std::cout << encoderRight->GetGlobalError().GetMessage() << std::endl;
	std::cout << "Encoders Init'd" << encoderLeft->Get() << ":" << encoderRight->Get() << std::endl;

	encoderLeft->SetReverseDirection(true);
;	encoderRight->SetReverseDirection(true);

	sgroupDriveL.reset(new SpeedControllerGroup(*sparkDriveLF, *sparkDriveLR));
	sgroupDriveR.reset(new SpeedControllerGroup(*sparkDriveRF, *sparkDriveRR));

	solenoidIntakeLock.reset(new DoubleSolenoid(PCMPorts::INTAKE_LOCK_FORWARD, PCMPorts::INTAKE_LOCK_REVERSE));
	solenoidIntakeDeploy.reset(new DoubleSolenoid(PCMPorts::INTAKE_DEPLOY_FORWARD, PCMPorts::INTAKE_DEPLOY_REVERSE));

	servoRelease.reset(new Servo(6));
	
	robotDrive.reset(new DifferentialDrive(*sgroupDriveL, *sgroupDriveR));
}
