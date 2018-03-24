#include "Intake.h"
#include "../RoboMap.h"
#include "Lift.h"
#include "Commands/Lift/LiftJoystick.h"
Lift::Lift() :
	PIDSubsystem("Lift", 1.0,0,0)
{
	this->LiftSpark = RoboMap::sparkLift;
	this->LiftEncoder = RoboMap::encoderLift;

	this->LiftSpark->SetSafetyEnabled(false);
	Disable();

	GetPIDController()->SetContinuous(false);
	
}

void Lift::InitDefaultCommand()
{
	SetDefaultCommand(new LiftJoystick());
}


void Lift::SetPosition(bool up)
{
	if (up) {
		SetSetpoint(POS_UP);
	}
	else {
		SetSetpoint(POS_DOWN);
	}
	Enable();
}

void Lift::SetPower(double val)
{
	LiftSpark->Set(val);
}

double Lift::ReturnPIDInput()
{
	//std::cout << LiftEncoder->Get() << std::endl;
	return LiftEncoder->Get();
}

void Lift::UsePIDOutput(double output)
{
	//std::cout << output << std::endl;
	LiftSpark->Set(output);
}
