#include "IntakeBinary.h"
#include "RoboMap.h"

IntakeBinary::IntakeBinary(bool inVal)
{
	this->intakeSpark = RoboMap::sparkIntake.get();
	this->val = inVal;
	this->solenoid = RoboMap::solenoidIntakeLock.get();
	this->SetTimeout(0.5);
	
}

void IntakeBinary::Initialize()
{
	Robot::victoryConnect->SendPacket(0, "command_intake_binary", "init");
}

void IntakeBinary::Execute()
{
	
	double bVal = 0;

	DoubleSolenoid::Value solVal= DoubleSolenoid::kForward;

	if (this->val == 1) {
		solVal = DoubleSolenoid::kReverse;
	}
	std::cout << solVal << std::endl;
	intakeSpark->Set(bVal);
	solenoid->Set(solVal);
	Robot::victoryConnect->SendPacket(0, "command_intake_binary", "running");
}



void IntakeBinary::End() { intakeSpark->Set(0); Robot::victoryConnect->SendPacket(0, "command_intake_binary", "stopped");
solenoid->Set(DoubleSolenoid::kOff);
}

void IntakeBinary::Interrupted() { intakeSpark->Set(0); Robot::victoryConnect->SendPacket(0, "command_intake_binary", "stopped");
solenoid->Set(DoubleSolenoid::kOff);
}