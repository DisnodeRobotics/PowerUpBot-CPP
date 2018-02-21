
#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class ReleaseOnce : public Command {
private:

	Servo* releaseServo;


public:
	ReleaseOnce();
	void Initialize();
	void Execute();
	bool IsFinished() { return true; }
	void End();
	void Interrupted();
};