#pragma once
#include <Commands/Subsystem.h>
#include "Robot.h"

class LiftJoystick : public Command
{
public:
	LiftJoystick();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:

};
