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

	Waypoint p1 = { 0, 0, 0 };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
	Waypoint p2 = { -1, 0, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
	Waypoint p3 = { 2, 0, 0 };             // Waypoint @ x= 2, y= 4, exit angle= 0 radians
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;

	TrajectoryCandidate candidate;
	pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_LOW, 0.001, 15.0, 10.0, 60.0, &candidate);

	int length = candidate.length;
	Segment *trajectory = new Segment[length];
	std::cout << "Generating... " << std::endl;
	pathfinder_generate(&candidate, trajectory);
	std::cout << "Mofiying... " << std::endl;
	Segment *leftTrajectory = new Segment[length];
	Segment *rightTrajectory = new Segment[length];

	double wheelbase_width = 0.6;

	pathfinder_modify_tank(trajectory, length, leftTrajectory, rightTrajectory, wheelbase_width);
	std::cout << "Example Point: " << std::endl << "X/Y: " << leftTrajectory[5].x << "/" << leftTrajectory[1].y << std::endl
		<< "Accel: " << leftTrajectory[1].acceleration<< std::endl
		<< "Vel: " << leftTrajectory[1].velocity << std::endl
		<< "Pos: " << leftTrajectory[1].position << std::endl;
	delete[] points;
	delete[] trajectory;
	delete[] leftTrajectory;
	delete[] rightTrajectory;
	
}

void TestPathfinder::Execute() 
{
	//std::cout << "Running... " << std::endl;


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