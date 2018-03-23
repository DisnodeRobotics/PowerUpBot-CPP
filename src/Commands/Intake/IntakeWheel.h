
#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class IntakeWheel : public Command {
private:
	double val;
	

public:
	IntakeWheel(double val);
	void Initialize();
	void Execute();
	bool IsFinished() { return IsTimedOut(); }
	void End();
	void Interrupted();
};