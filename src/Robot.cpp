#include "WPILib.h"
#include "Robot.h"
#include "Commands/Drive/DriveJoystick.h"
using namespace frc;


void Robot::RobotInit() {
	drivetrain.reset(new Drivetrain());
	oi.reset(new OI());
	RoboMap::navX->ZeroYaw();

	drivejoystick.reset(new DriveJoystick());

}
void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();

#ifdef BROWNOUT
	if (DriverStation::GetInstance().IsSysBrownedOut())
		printf("ERROR: System brownout!\n");
}
#endif
}

void Robot::AutonomousInit()
{
}

void Robot::AutonomousPeriodic()
{
	
	Scheduler::GetInstance()->Run();


#ifdef BROWNOUT
	if (DriverStation::GetInstance().IsSysBrownedOut())
		printf("ERROR: System brownout!\n");
}
#endif
}

void Robot::TeleopInit()
{

	//RoboMap::NavX->Reset();
	printf("Info: Reset NavX\n");

	drivejoystick->Start();

}



void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();


#ifdef BROWNOUT
	if (DriverStation::GetInstance().IsSysBrownedOut())
		printf("ERROR: System brownout!\n");
}
#endif
}

void Robot::TestInit()
{

}

void Robot::TestPeriodic()
{
}

START_ROBOT_CLASS(Robot)