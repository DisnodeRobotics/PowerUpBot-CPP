#pragma once

#include "Commands/CommandGroup.h"
#include "Robot.h"
#include <Timer.h>
#include <pathfinder.h>

class TestPathfinder : public CommandGroup
{
private:
	int length;
	std::shared_ptr<Segment> leftTrajectory;
	std::shared_ptr<Segment> rightTrajectory;

	double wheelbase_width = 0.6;

	double wheel_circumference = 6;
	double max_velocity = 4;

	double encoder_ticks = 20;
	double drive_ratio = 10.71;
	double ticks_per_rev = encoder_ticks * drive_ratio;


	EncoderFollower leftFollower;
	EncoderFollower rightFollower;
	EncoderConfig configL;
	EncoderConfig configR;

public:
	TestPathfinder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


