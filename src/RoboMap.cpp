#include "RoboMap.h"



void RoboMap::Init()
{
	sparkDriveLF.reset(new Spark(PWMPorts::DRIVE_LEFT_FRONT));
	sparkDriveLR.reset(new Spark(PWMPorts::DRIVE_LEFT_REAR));
	sparkDriveRF.reset(new Spark(PWMPorts::DRIVE_RIGHT_FRONT));
	sparkDriveRR.reset(new Spark(PWMPorts::DRIVE_RIGHT_REAR));

	sparkClimbL.reset(new Spark(PWMPorts::CLIMB_LEFT));
	sparkClimbR.reset(new Spark(PWMPorts::CLIMB_RIGHT));

	sparkIntakeL.reset(new Spark(PWMPorts::INTAKE_LEFT));
	sparkIntakeR.reset(new Spark(PWMPorts::INTAKE_RIGHT));

	sparkLift.reset(new Spark(PWMPorts::LIFT));

	navX.reset(new AHRS(SPI::Port::kMXP));
}
