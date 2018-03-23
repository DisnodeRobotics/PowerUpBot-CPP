
#include "LiftToPosition.h"
#include "RoboMap.h"



LiftToPosition::LiftToPosition(bool up) : Command()
{
	Requires(Robot::lift.get());
	SetTimeout(10);
	m_up = up;
}
void LiftToPosition::Initialize()
{
	Robot::victoryConnect->SendPacket(0, "command_intake_lock", "init;no_data;" + to_string(m_up) + ";");
	Robot::lift->SetPower(0);
}
void LiftToPosition::Execute()
{
	Robot::lift->SetPosition(m_up);
	if (m_up) {
		Robot::victoryConnect->SendPacket(0, "command_intake_lock", "running;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_lock", "running;false;");
	}

}


void LiftToPosition::End()
{
	if (m_up) {
		Robot::victoryConnect->SendPacket(0, "command_intake_lock", "End;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_lock", "End;false;");
	}
	Robot::lift->SetPower(0);
}

void LiftToPosition::Interrupted()
{
	if (m_up) {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "Interrupted;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "Interrupted;false;");
	}
	Robot::lift->SetPower(0);
}