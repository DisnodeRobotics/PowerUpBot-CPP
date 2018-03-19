#include "IntakeLock.h"
#include "RoboMap.h"



IntakeLock::IntakeLock(bool lock) : Command()
{
	Requires(Robot::intake.get());
	SetTimeout(0.5);
	m_lock = lock;
}
void IntakeLock::Initialize()
{
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "init;no_data;" + to_string(m_lock) + ";");
	Robot::intake->SetLock(false);
}
void IntakeLock::Execute()
{
	Robot::intake->SetLock(m_lock);
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "running;"+to_string(m_lock)+";");
}


void IntakeLock::End() 
{ 
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "ended;no_data;" + to_string(m_lock) + ";");
}

void IntakeLock::Interrupted()
{ 
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "interrupted;" + to_string(m_lock) + ";");
}