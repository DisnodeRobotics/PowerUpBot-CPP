#pragma once

#include <Commands/Command.h>
#include <Robot.h>


class IntakeDeploy : public Command {
private:

	DoubleSolenoid * m_solenoid;
	bool m_deploy;

public:
	IntakeDeploy(bool deploy);
	void Initialize();
	void Execute();
	bool IsFinished() { return IsTimedOut(); }
	void End();
	void Interrupted();
};