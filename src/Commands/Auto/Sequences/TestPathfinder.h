#pragma once

#include "Commands/CommandGroup.h"
#include "Robot.h"
#include <Timer.h>
#include <pathfinder.h>
#include "../../Paths/Profile.h"

class TestPathfinder : public CommandGroup
{
private:
	int length;
	std::shared_ptr<Segment> leftTrajectory;
	std::shared_ptr<Segment> rightTrajectory;

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


