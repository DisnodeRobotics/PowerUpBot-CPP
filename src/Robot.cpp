#include "WPILib.h"
#include "Compressor.h"
#include "Robot.h"
#include "Commands/Drive/DriveJoystick.h"
#include "Commands/LiftBinary.h"
#include "Commands/Auto/Autonomous.h"
#include <memory>
#include "ctre\Phoenix.h"
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<VictoryConnectClient> Robot::victoryConnect;


void Robot::RobotInit() {
	RoboMap::Init();

	std::cout << "ROBO IS DA STARTING" << std::endl;
	

	victoryConnect.reset(new VictoryConnectClient());
	drivetrain.reset(new Drivetrain());
	
	oi.reset(new OI());

	RoboMap::navX->ZeroYaw();
	printf("Zeroed Yaw in init!\n");
	
	drivejoystick.reset(new DriveJoystick());
	autonomousCommand.reset(new Autonomous());

	CameraServer::GetInstance()->StartAutomaticCapture();

	NetworkTable::SetTeam(4056);
	thread vicInitThread(Robot::VictoryInit);
	vicInitThread.detach();



}
void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	//Scheduler::GetInstance()->Run();

}

void Robot::AutonomousInit()
{
	std::cout << "ROBO IS DA STARTING DA AUTO" << std::endl;
	autonomousCommand->Start();
	
	
}

void Robot::AutonomousPeriodic()
{
	
	
	Scheduler::GetInstance()->Run();

}

void Robot::TeleopInit()
{

	RoboMap::navX->Reset();
	printf("Info: Reset NavX\n");

	drivejoystick->Start();

}



void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();

	
	//RoboMap::solenoidPlatform1->Set(DoubleSolenoid::kForward);
}

void Robot::TestInit()
{
}

void Robot::TestPeriodic()
{
}

void Robot::VictoryInit() {
	std::cout << "STARTING!" << std::endl;
	Robot::victoryConnect->Connect("10.40.56.7");
	
}
void Robot::VictoryPeroidic()
{
	Robot::victoryConnect->SendPacket(0, "encoder_drive",
		to_string(drivetrain->GetEncoderLDistance()) + " " +
		to_string(drivetrain->GetEncoderRDistance()) + " " +
		to_string(drivetrain->GetAverageEncoderDistance()) + " ");

	//NAV X
	Robot::victoryConnect->SendPacket(0, "navx_heading",
		to_string(RoboMap::navX->GetFusedHeading()) + " ");


	Robot::victoryConnect ->SendPacket(0, "motor_power", "drive_left_front " + to_string(RoboMap::sparkDriveLF->Get()));
	Robot::victoryConnect->SendPacket(0, "motor_power", "drive_left_rear " + to_string(RoboMap::sparkDriveLR->Get()));
	Robot::victoryConnect->SendPacket(0, "motor_power", "drive_right_front " + to_string(RoboMap::sparkDriveRF->Get()));
	Robot::victoryConnect->SendPacket(0, "motor_power", "drive_right_rear " + to_string(RoboMap::sparkDriveRR->Get()));

	
}



START_ROBOT_CLASS(Robot)