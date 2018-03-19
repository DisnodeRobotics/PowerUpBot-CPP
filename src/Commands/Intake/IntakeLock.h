#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class IntakeLock : public Command {
private:

	DoubleSolenoid* m_solenoid;
	bool m_lock;

public:
	IntakeLock(bool lock);
	void Initialize();
	void Execute();
	bool IsFinished() { return IsTimedOut(); }
	void End();
	void Interrupted();
};