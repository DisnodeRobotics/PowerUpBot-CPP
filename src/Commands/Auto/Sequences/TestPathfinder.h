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

	double wheel_circumference = 18.49; // 6in wheel
	double max_velocity = 5;

	double encoder_ticks = 40;
	double drive_ratio = 0.107; // 10.71:1 Ratio
	double ticks_per_rev = encoder_ticks * drive_ratio;
	EncoderConfig configL;
	EncoderConfig configR;
	EncoderFollower leftFollower;
	EncoderFollower rightFollower;

	

public:
	TestPathfinder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


