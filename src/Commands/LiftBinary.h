

#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class LiftBinary : public Command {
private:
	bool val;
	Spark* liftSpark;


public:
	LiftBinary(bool val);
	void Initialize();
	void Execute();
	bool IsFinished() { return false; }
	void End();
	void Interrupted();
};