#include "IntakeBinary.h"
#include "RoboMap.h"

IntakeBinary::IntakeBinary(bool val)
{
	this->intakeSpark = RoboMap::sparkIntake.get();
	this->val = val;

}

void IntakeBinary::Initialize()
{
	Robot::victoryConnect->SendPacket(0, "command_intake_binary", "init");
}

void IntakeBinary::Execute()
{
	double bVal = 0;
	if (val) {
		bVal = 1;
	}
	else {
		bVal = -0.3;
	}
	intakeSpark->Set(bVal);
	Robot::victoryConnect->SendPacket(0, "command_intake_binary", "running");
}



void IntakeBinary::End() { intakeSpark->Set(0); Robot::victoryConnect->SendPacket(0, "command_intake_binary", "stopped");
}

void IntakeBinary::Interrupted() { intakeSpark->Set(0); Robot::victoryConnect->SendPacket(0, "command_intake_binary", "stopped");
}