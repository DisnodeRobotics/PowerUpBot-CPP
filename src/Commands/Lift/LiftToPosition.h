#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class LiftToPosition : public Command {
private:


	bool m_up;

public:
	LiftToPosition(bool up);
	void Initialize();
	void Execute();
	bool IsFinished() { return IsTimedOut(); }
	void End();
	void Interrupted();
};