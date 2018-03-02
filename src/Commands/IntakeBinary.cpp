#include "IntakeBinary.h"
#include "RoboMap.h"

IntakeBinary::IntakeBinary(bool val)
{
	this->intakeSpark = RoboMap::sparkIntake.get();
	this->val = val;

}

void IntakeBinary::Initialize()
{

}

void IntakeBinary::Execute()
{
	double bVal = 0;
	if (val) {
		bVal = 1;
	}
	else {
		bVal = -0.3;
	}
	intakeSpark->Set(bVal);
}



void IntakeBinary::End() { intakeSpark->Set(0); }

void IntakeBinary::Interrupted() { intakeSpark->Set(0); }