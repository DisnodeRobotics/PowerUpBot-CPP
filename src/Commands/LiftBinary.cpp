#include "LiftBinary.h"
#include "RoboMap.h"
LiftBinary::LiftBinary(bool val)
{
	this->liftSpark = RoboMap::sparkLift.get();
	this->val = val;

}

void LiftBinary::Initialize()
{
	
}

void LiftBinary::Execute()
{
	double bVal = 0;
	if (val) {
		bVal = 1;
	}
	else {
		bVal = -1;
	}
	liftSpark->Set(bVal);
}



void LiftBinary::End() { liftSpark->Set(0); }

void LiftBinary::Interrupted() {liftSpark->Set(0); }