#include "WPILib.h"
#include "Robot.h"
#include "Commands/Drive/DriveJoystick.h"
using namespace frc;


void Robot::RobotInit() {
	drivetrain.reset(new Drivetrain());
	oi.reset(new OI());
	RoboMap::navX->ZeroYaw();

	drivejoystick.reset(new DriveJoystick());

	victoryConnect.reset(new VictoryConnectClient());
	victoryConnect->Connect("10.40.56.7");

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

	VictoryPeroidic();
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

void Robot::VictoryPeroidic()
{
	victoryConnect->SendPacket(0, "encoder_drive", 
		to_string(drivetrain->GetEncoderLDistance()) + ";" +
		to_string(drivetrain->GetEncoderRDistance()) + ";" +
		to_string(drivetrain->GetAverageEncoderDistance()) + ";");
	
	victoryConnect->SendPacket(0, "navx_heading_rio",
		to_string(RoboMap::navX->GetFusedHeading()) + ";");

}



START_ROBOT_CLASS(Robot)