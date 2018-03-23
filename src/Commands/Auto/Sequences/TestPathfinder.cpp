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
	RoboMap::navX->Reset();

	int POINT_LENGTH = 3;

	Waypoint *points = new Waypoint[POINT_LENGTH];

	Waypoint p1 = { 0, 0 , d2r(30) };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
	Waypoint p2 = { 3.5, 2,d2r(270)};             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
	Waypoint p3 = { 5, 3.5,0 };

	points[0] = p1;
	points[1] = p2;
	points[2] = p3;


	TrajectoryCandidate candidate;
	pathfinder_prepare(points, 
		POINT_LENGTH, 
		FIT_HERMITE_CUBIC, 
		PATHFINDER_SAMPLES_LOW, 
		0.015, // time
		DriveProfile::MAX_VELOCITY , 
		DriveProfile::MAX_ACCELERATION,
		DriveProfile::MAX_JERK, 
		&candidate);

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


	configL = { Robot::drivetrain->GetEncoderLDistance(), DriveProfile::ENCODER_TICKS_PER_REV, DriveProfile::TICKS_PER_REV ,1.2,0.0,0.5,1.0 / DriveProfile::MAX_VELOCITY, 0};
	configR = { Robot::drivetrain->GetEncoderRDistance(), DriveProfile::ENCODER_TICKS_PER_REV, DriveProfile::TICKS_PER_REV, 1.2,0.0,0.5,1.0 / DriveProfile::MAX_VELOCITY, 0};

	delete[] points;
	delete[] trajectory;
	
	
}

void TestPathfinder::Execute()
{



	double l = pathfinder_follow_encoder(configL, &leftFollower, leftTrajectory.get(), length, Robot::drivetrain->GetEncoderLDistance());
	double r = pathfinder_follow_encoder(configR, &rightFollower, rightTrajectory.get(), length, Robot::drivetrain->GetEncoderRDistance());
	
	
	double gyro = RoboMap::navX->GetFusedHeading();
	if (gyro > 180) {
		gyro -= 360;
	}
	double desired = r2d(leftFollower.heading);

	double dif = desired - gyro;

	double turn = 3.0 * (-1.0 / 80.0) * dif * -1 ;
	l += turn;
	r -= turn;
	
	//Robot::drivetrain->SetTankDrive(l + turn, r - turn);
	RoboMap::sgroupDriveL->Set(l );
	RoboMap::sgroupDriveR->Set( -r );
	double accel = RoboMap::navX->GetRawAccelX();
	if (accel > maxaccel) {
		maxaccel = accel;
	}
	//std::cout << "Accel:" << RoboMap::navX->GetRawAccelX() << std::endl;
	//std::cout << "Ve: " << RoboMap::navX->GetVelocityX() << std::endl;
	 
	std::cout << "Pathfinder: " << "L: " << l << " R: " << r << " Gyro/Target: " << gyro << "/" << desired << " Turn: " << turn << " Last Error: " << leftFollower.last_error << " Encoders: " << Robot::drivetrain->GetEncoderLDistance() <<"/"<<Robot::drivetrain->GetEncoderRDistance() << std::endl;
	//Robot::drivetrain->SetTankDrive(0.5,0.5);

}


bool TestPathfinder::IsFinished()
{
	return leftFollower.finished &&  rightFollower.finished;
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