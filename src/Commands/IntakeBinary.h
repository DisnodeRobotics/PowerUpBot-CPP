
#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class IntakeBinary : public Command {
private:
	bool val;
	Spark* intakeSpark;


public:
	IntakeBinary(bool val);
	void Initialize();
	void Execute();
	bool IsFinished() { return false; }
	void End();
	void Interrupted();
};