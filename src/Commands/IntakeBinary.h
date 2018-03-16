
#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class IntakeBinary : public Command {
private:
	bool val;
	Spark* intakeSpark;
	DoubleSolenoid *solenoid;

public:
	IntakeBinary(bool val);
	void Initialize();
	void Execute();
	bool IsFinished() { return IsTimedOut(); }
	void End();
	void Interrupted();
};