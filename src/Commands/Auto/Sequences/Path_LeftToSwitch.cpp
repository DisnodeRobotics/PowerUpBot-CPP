#include "Path_LeftToSwitch.h"
#include "Robot.h"
#include "RoboMap.h"

using namespace std;
Path_LeftToSwitch::Path_LeftToSwitch()
{

	Requires(Robot::drivetrain.get());
	SetTimeout(4);
}

void Path_LeftToSwitch::Initialize()
{
	/*
	RoboMap::navX->Reset();

	int POINT_LENGTH = 3;

	Waypoint *points = new Waypoint[POINT_LENGTH];
	std::cout << DriverStation::GetInstance().GetLocation() << std::endl;

	Waypoint p1 = { 0, 0 , d2r(0) };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
	Waypoint p2 = { 2,0,d2r(0) };  
	Waypoint p3 = { 2.2,0,d2r(0) };  // Waypoint @ x=-1, y= 2, exit angle= 0 radians
					  //Waypoint p2 = { 2, 0.5,d2r(90) };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians


	bool leftSwitch = false;
	bool leftScale = false;
	if (DriverStation::GetInstance().GetGameSpecificMessage()[0] == 'L') {
		leftSwitch = true;
	}
	if (DriverStation::GetInstance().GetGameSpecificMessage()[1] == 'L') {
		leftScale = true;
	}
	
	if (leftSwitch) {
		std::cout << "L POS" << std::endl;
		p1 = { 0, 0 , d2r(5) };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
		p2 = { 0.6, 0.3,d2r(0) };
		p3 = { 0.6, 0.3,d2r(0) };
	}
	else if (leftScale){
		std::cout << "R POS" << std::endl;
		p1 = { 0, 0 , d2r(-30) };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
		p2 = { 2, -2,d2r(20) };
		p3 = { 4, -1.2,d2r(0) };
	}
	else {
		p1 = { 0, 0 , d2r(-30) };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
		p2 = { 2, -2.5,d2r(0) };
		p3 = { 2.2, -2.5,d2r(0) };
	}


	
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	//points[1] = p2;

	TrajectoryCandidate candidate;
	pathfinder_prepare(points,
		POINT_LENGTH,
		FIT_HERMITE_CUBIC,
		PATHFINDER_SAMPLES_LOW,
		0.015, // time
		DriveProfile::MAX_VELOCITY,
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


	configL = { Robot::drivetrain->GetEncoderLDistance(), DriveProfile::ENCODER_TICKS_PER_REV, DriveProfile::TICKS_PER_REV ,1,0.0,0.5,1.0 / DriveProfile::MAX_VELOCITY, 0 };
	configR = { Robot::drivetrain->GetEncoderRDistance(), DriveProfile::ENCODER_TICKS_PER_REV, DriveProfile::TICKS_PER_REV, 1.0,0.0,0.5,1.0 / DriveProfile::MAX_VELOCITY, 0 };

	delete[] points;
	delete[] trajectory;
	*/

}

void Path_LeftToSwitch::Execute()
{


	/*
	double l = pathfinder_follow_encoder(configL, &leftFollower, leftTrajectory.get(), length, Robot::drivetrain->GetEncoderLDistance());
	double r = pathfinder_follow_encoder(configR, &rightFollower, rightTrajectory.get(), length, Robot::drivetrain->GetEncoderRDistance());


	double gyro = RoboMap::navX->GetFusedHeading();
	if (gyro > 179) {
		gyro -= 359;
	}
	double desired = r2d(leftFollower.heading);
	if (desired > 179) {
		desired -= 359  ;
	}
	double dif = desired - gyro;

	double turn = 0.9 * (-1.0 / 80.0) * dif * -1;
	l += turn;
	r -= turn;

	//Robot::drivetrain->SetTankDrive(l + turn, r - turn);
	RoboMap::sgroupDriveL->Set(l);
	RoboMap::sgroupDriveR->Set(-r);
	double accel = RoboMap::navX->GetRawAccelX();
	if (accel > maxaccel) {
		maxaccel = accel;
	}
	//std::cout << "Accel:" << RoboMap::navX->GetRawAccelX() << std::endl;
	//std::cout << "Ve: " << RoboMap::navX->GetVelocityX() << std::endl;

	std::cout << "Pathfinder: " << "L: " << l << " R: " << r << " Gyro/Target: " << gyro << "/" << desired << " Turn: " << turn << " Last Error: " << leftFollower.last_error << " Encoders: " << Robot::drivetrain->GetEncoderLDistance() << "/" << Robot::drivetrain->GetEncoderRDistance() << std::endl;
	//Robot::drivetrain->SetTankDrive(0.5,0.5);
	*/
	Robot::drivetrain->SetArcadeDrive(0.6, 0);
}


bool Path_LeftToSwitch::IsFinished()
{
	//return leftFollower.finished &&  rightFollower.finished;
	return IsTimedOut();
}

void Path_LeftToSwitch::End()
{

	printf("Info: End auto driving.\n");
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);

}

void Path_LeftToSwitch::Interrupted()
{

	printf("Info: End auto driving.\n");
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);

}