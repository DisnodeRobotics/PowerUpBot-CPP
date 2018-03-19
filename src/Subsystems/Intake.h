#pragma once
#include "Commands/Subsystem.h"

#include "WPILib.h"
class Intake : public Subsystem
{
public:
private:
	std::shared_ptr<Spark> WheelSpark;
	std::shared_ptr<DoubleSolenoid> LockSolenoid;
	std::shared_ptr<DoubleSolenoid> DeploySolenoid;

public:
	Intake();


	void InitDefaultCommand();
	void SetIntakeWheels(double val);
	void SetDeploy(bool val);
	void SetLock(bool val);
	void PIDDisable();
	void PIDEnable();
};

