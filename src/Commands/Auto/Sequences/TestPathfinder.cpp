#include "TestPathfinder.h"
#include "Robot.h"
#include "RoboMap.h"
#include <stdlib.h>
using namespace std;
TestPathfinder::TestPathfinder()
{
	Requires(Robot::drivetrain.get());
	SetTimeout(30);
}

void TestPathfinder::Initialize()
{
	int POINT_LENGTH = 3;

	Waypoint *points = new Waypoint[POINT_LENGTH];

	Waypoint p1 = { 0, 0, 0};      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
	Waypoint p2 = { 0, 0, d2r(45)};             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
	Waypoint p3 = { 1, 1, 0 };             // Waypoint @ x= 2, y= 4, exit angle= 0 radians
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;

	TrajectoryCandidate candidate;
	pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_LOW, 0.02, DriveProfile::MAX_VELOCITY, 10.0, 60.0, &candidate);

	length = candidate.length;
	Segment *trajectory = new Segment[length];
	std::cout << "Generating... " << std::endl;
	
	pathfinder_generate(&candidate, trajectory);
	std::cout << "Mofiying... " << std::endl;
	
	leftTrajectory.reset(new Segment[length]);
	rightTrajectory.reset(new Segment[length]);
	

	pathfinder_modify_tank(trajectory, length, leftTrajectory.get(), rightTrajectory.get(), DriveProfile::WHEELBASE_WIDTH);
	leftFollower.last_error = 0;
	leftFollower.segment = 0;
	leftFollower.finished = 0;

	rightFollower.last_error = 0;
	rightFollower.segment = 0;
	rightFollower.finished = 0;


	configL = { Robot::drivetrain->GetEncoderLDistance(), DriveProfile::TICKS_PER_REV, DriveProfile::WHEEL_CIRCUMFERENCE, 1.0,0.0,0.0,1.0 / DriveProfile::MAX_VELOCITY, 0 };
	configR = { Robot::drivetrain->GetEncoderRDistance(), DriveProfile::TICKS_PER_REV, DriveProfile::WHEEL_CIRCUMFERENCE, 1.0,0.0,0.0,1.0 / DriveProfile::MAX_VELOCITY, 0 };

	delete[] points;
	delete[] trajectory;
	
	
}

void TestPathfinder::Execute() 
{
	


	double l = pathfinder_follow_encoder(configL, &leftFollower, leftTrajectory.get(), length, Robot::drivetrain->GetEncoderLDistance());
	double r = pathfinder_follow_encoder(configR, &rightFollower, rightTrajectory.get(), length, Robot::drivetrain->GetEncoderRDistance());

	double gyro = RoboMap::navX->GetFusedHeading();

	double desired = r2d(leftFollower.heading);
	//double dif = desired - gyro;
	double turn = 0;

	RoboMap::sgroupDriveL->Set(l + turn);
	RoboMap::sgroupDriveR->Set(r - turn);


	std::cout << "Running... " << std::endl;
	std::cout << leftFollower.segment << " " << leftFollower.output << std::endl;
	std::cout << "Encoder L" << Robot::drivetrain->GetEncoderLDistance() << std::endl;
	std::cout << "Encoder R" << Robot::drivetrain->GetEncoderRDistance() << std::endl;

	std::cout << "l" << l << std::endl;
	std::cout << " R" <<r << std::endl;
	//std::cout << "Pathfinder: " << l << "/" << r << std::endl;
	//Robot::drivetrain->SetTankDrive(0.5,0.5);

}


bool TestPathfinder::IsFinished()
{
	return IsTimedOut();
}

void TestPathfinder::End()
{
	
	printf("Info: End auto driving.\n");
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);

}

void TestPathfinder::Interrupted() 
{
	
	printf("Info: End auto driving.\n");
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
	
}