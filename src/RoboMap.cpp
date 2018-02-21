#include "RoboMap.h"
std::shared_ptr<Spark> RoboMap::sparkDriveLF;
std::shared_ptr<Spark> RoboMap::sparkDriveLR;
std::shared_ptr<Spark> RoboMap::sparkDriveRF;
std::shared_ptr<Spark> RoboMap::sparkDriveRR;


std::shared_ptr<Spark> RoboMap::sparkIntake;


std::shared_ptr<Spark> RoboMap::sparkLift;
std::shared_ptr<Servo> RoboMap::servoRelease;

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

	navX.reset(new AHRS(SPI::Port::kMXP));
	encoderLeft.reset(new Encoder(0, 1));
	encoderRight.reset(new Encoder(2, 3));
	encoderRight->SetReverseDirection(true);

	sgroupDriveL.reset(new SpeedControllerGroup(*sparkDriveLF, *sparkDriveLR));
	sgroupDriveR.reset(new SpeedControllerGroup(*sparkDriveRF, *sparkDriveRR));
	

	servoRelease.reset(new Servo(6));
	
	robotDrive.reset(new DifferentialDrive(*sgroupDriveL, *sgroupDriveR));
}
