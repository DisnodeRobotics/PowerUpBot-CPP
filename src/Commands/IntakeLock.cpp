#include "IntakeLock.h"
#include "RoboMap.h"



IntakeLock::IntakeLock()
{
	this->intakeSpark = RoboMap::sparkIntake.get();
}
void IntakeLock::Initialize()
{
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "init");
}
void IntakeLock::Execute()
{
	
	intakeSpark->Set(0.4);
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "running");
}


void IntakeLock::End() 
{ 
	intakeSpark->Set(0); 
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "stopped");
}

void IntakeLock::Interrupted()
{ 
	intakeSpark->Set(0); 
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "stopped");
}