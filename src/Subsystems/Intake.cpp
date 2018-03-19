#include "Intake.h"
#include "../RoboMap.h"

Intake::Intake() :
	Subsystem("Intake")
{
	WheelSpark = RoboMap::sparkIntake;
	LockSolenoid = RoboMap::solenoidIntakeLock;
	DeploySolenoid = RoboMap::solenoidIntakeDeploy;
}

void Intake::InitDefaultCommand()
{

}

void Intake::SetIntakeWheels(double val)
{
	WheelSpark->Set(val);
}

void Intake::SetDeploy(bool val)
{
	if (val) {
		DeploySolenoid->Set(DoubleSolenoid::kForward);
	}
	else {
		DeploySolenoid->Set(DoubleSolenoid::kReverse);
	}
}

void Intake::SetLock(bool val)
{
	if (val) {
		LockSolenoid->Set(DoubleSolenoid::kForward);
	}
	else {
		LockSolenoid->Set(DoubleSolenoid::kReverse);
	}
}


Intake::~Intake()
{
}
