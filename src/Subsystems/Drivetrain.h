#pragma once
#include "Commands/Subsystem.h"
#include "RobotDrive.h"
#include "WPILib.h"
class Drivetrain : public Subsystem
{
private:
	std::shared_ptr<Spark> Spark1;
	std::shared_ptr<Spark> Spark2;
	std::shared_ptr<Spark> Spark3;
	std::shared_ptr<Spark> Spark4;
	std::shared_ptr<SpeedControllerGroup> GroupL;
	std::shared_ptr<SpeedControllerGroup> GroupR;
	std::shared_ptr<DifferentialDrive> robotDrive;
	std::shared_ptr<Encoder> encoderL;
	std::shared_ptr<Encoder> encoderR;
public:
	Drivetrain();
	void SetManualDrive(float outputPower, float curveSharpness);
	void SetArcadeDrive(float movePower, float rotatePower);
	void SetTankDrive(float leftPower, float rightPower);
	void Stop();

	double GetEncoderLDistance();
	double GetEncoderRDistance();
	double GetAverageEncoderDistance();
	void InitDefaultCommand();
	std::shared_ptr<Spark> GetSpark(int id);

	void PIDDisable();
	void PIDEnable();
};

