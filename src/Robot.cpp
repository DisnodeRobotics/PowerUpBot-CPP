#include "WPILib.h"
#include "Robot.h"
using namespace frc;


void Robot::RobotInit() {
	drivetrain.reset(new Drivetrain());
	oi.reset(new OI());
	RoboMap::navX->ZeroYaw();


}

START_ROBOT_CLASS(Robot)