#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class IntakeLock : public Command {
private:

	Spark* intakeSpark;


public:
	IntakeLock();
	void Initialize();
	void Execute();
	bool IsFinished() { return false; }
	void End();
	void Interrupted();
};