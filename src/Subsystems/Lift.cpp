#include "Intake.h"
#include "../RoboMap.h"
#include "Lift.h"
#include "Commands/Lift/LiftJoystick.h"
Lift::Lift() :
	PIDSubsystem("Lift", 1.0,0,0)
{
	this->LiftSpark = RoboMap::sparkLift;
	this->LiftEncoder = RoboMap::encoderLift;
	Enable();

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
}

void Lift::SetPower(double val)
{
	LiftSpark->Set(val);
}

double Lift::ReturnPIDInput()
{
	return LiftEncoder->Get();
}

void Lift::UsePIDOutput(double output)
{
	LiftSpark->Set(output);
}
