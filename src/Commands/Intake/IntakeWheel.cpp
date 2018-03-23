#include "IntakeWheel.h"
#include "RoboMap.h"

IntakeWheel::IntakeWheel(double inVal)
{
	Requires(Robot::intake.get());
	this->val = inVal;
	
	this->SetTimeout(0.5);
	
}

void IntakeWheel::Initialize()
{
	Robot::victoryConnect->SendPacket(0, "command_intake_wheel", "init;"+ to_string(val) + ";");
}

void IntakeWheel::Execute()
{
	std::cout << "intake" << std::endl;
	Robot::intake->SetIntakeWheels(val);

	Robot::victoryConnect->SendPacket(0, "command_intake_wheel", "running" + to_string(val) + ";");
}



void IntakeWheel::End() 
{ 
	Robot::intake->SetIntakeWheels(0);
	Robot::victoryConnect->SendPacket(0, "command_intake_wheel", "stopped" + to_string(val) + ";");

}

void IntakeWheel::Interrupted() {
	Robot::intake->SetIntakeWheels(0);
	Robot::victoryConnect->SendPacket(0, "command_intake_wheel", "stopped" + to_string(val) + ";");

}