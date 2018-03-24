#pragma once

#include "Commands/CommandGroup.h"
#include "Robot.h"
#include <Timer.h>
#include <pathfinder.h>
#include "../../Paths/Profile.h"

class Path_CenterToSwitch : public CommandGroup
{
private:
	
	int length;
	std::shared_ptr<Segment> leftTrajectory;
	std::shared_ptr<Segment> rightTrajectory;

	EncoderConfig configL;
	EncoderConfig configR;
	EncoderFollower leftFollower;
	EncoderFollower rightFollower;

	double maxaccel;

public:
	Path_CenterToSwitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


