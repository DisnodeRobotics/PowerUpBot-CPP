#pragma once
#include <OI.h>
#include <WPILib.h>
#include <Commands/Command.h>
#include "RoboMap.h"
#include <Subsystems/Drivetrain.h>
#include <Subsystems/Lift.h>
#include <Subsystems/Intake.h>
#include <victoryconnect\VictoryConnectClient.h>
class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> drivejoystick;
	std::unique_ptr<Command> liftjoystick;
	static std::shared_ptr<Drivetrain> drivetrain;
	static std::shared_ptr<Intake> intake;
	static std::shared_ptr<Lift> lift;


	static std::unique_ptr<OI> oi;
	static std::shared_ptr<VictoryConnectClient> victoryConnect;

	std::unique_ptr<CommandGroup> autonomousCommand;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestInit();
	virtual void TestPeriodic();
	static void VictoryInit();
	static void VictoryPeroidic();
};