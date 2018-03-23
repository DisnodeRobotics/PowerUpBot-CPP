#pragma once
#include "Commands/PIDSubsystem.h"

#include "WPILib.h"
class Lift : public PIDSubsystem
{
public:
private:
	const int POS_UP = 1700;
	const int POS_DOWN = 0;

	bool val;
	std::shared_ptr<Spark> LiftSpark;
	std::shared_ptr<Encoder> LiftEncoder;
public:
	Lift();


	void InitDefaultCommand();
	void SetPosition(bool up);
	void SetPower(double val);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
};

