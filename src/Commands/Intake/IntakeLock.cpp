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
	if (m_lock) {
		Robot::victoryConnect->SendPacket(0, "command_intake_lock", "running;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_lock", "running;false;");
	}
	
}


void IntakeLock::End() 
{ 
	if (m_lock) {
		Robot::victoryConnect->SendPacket(0, "command_intake_lock", "End;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_lock", "End;false;");
	}
}

void IntakeLock::Interrupted()
{ 
	if (m_lock) {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "Interrupted;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "Interrupted;false;");
	}
}