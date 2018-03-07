#include "LiftBinary.h"
#include "RoboMap.h"
LiftBinary::LiftBinary(bool val)
{
	this->liftSpark = RoboMap::sparkLift.get();
	this->val = val;

}

void LiftBinary::Initialize()
{
	Robot::victoryConnect->SendPacket(0, "command_lift_binary", "init");
}

void LiftBinary::Execute()
{
	double bVal = 0;
	if (val) {
		bVal = 1;
	}
	else {
		bVal = -1;
	}
	Robot::victoryConnect->SendPacket(0, "command_lift_binary", "running");
	liftSpark->Set(bVal);
}



void LiftBinary::End() { liftSpark->Set(0); Robot::victoryConnect->SendPacket(0, "command_lift_binary", "stopped");
}

void LiftBinary::Interrupted() {liftSpark->Set(0); Robot::victoryConnect->SendPacket(0, "command_lift_binary", "stopped");
}