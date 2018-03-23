#include "IntakeDeploy.h"

#include "RoboMap.h"



IntakeDeploy::IntakeDeploy(bool deploy) : Command()
{
	Requires(Robot::intake.get());
	SetTimeout(0.5);
	m_deploy = deploy;
}
void IntakeDeploy::Initialize()
{
	Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "init;no_data;" + to_string(m_deploy) + ";");
	Robot::intake->SetDeploy(false);
}
void IntakeDeploy::Execute()
{
	Robot::intake->SetDeploy(m_deploy);
	if (m_deploy) {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "running;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "running;false;");
	}

}


void IntakeDeploy::End()
{
	if (m_deploy) {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "End;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "End;false;");
	}
}

void IntakeDeploy::Interrupted()
{
	if (m_deploy) {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "Interrupted;true;");
	}
	else {
		Robot::victoryConnect->SendPacket(0, "command_intake_deploy", "Interrupted;false;");
	}
}