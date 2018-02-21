#include "IntakeLock.h"
#include "RoboMap.h"
IntakeLock::IntakeLock()
{
	this->intakeSpark = RoboMap::sparkIntake.get();

}

void IntakeLock::IntakeLock()
{

}

void IntakeLock::Execute()
{
	
	intakeSpark->Set(0.4);
}



void IntakeLock::End() { intakeSpark->Set(0); }

void IntakeLock::Interrupted() { intakeSpark->Set(0); }