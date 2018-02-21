#include "ReleaseOnce.h"
#include "RoboMap.h"
ReleaseOnce::ReleaseOnce()
{
	this->releaseServo = RoboMap::servoRelease.get();


}

void ReleaseOnce::Initialize()
{

}

void ReleaseOnce::Execute()
{
	releaseServo->SetAngle(90);
}



void ReleaseOnce::End() {}

void ReleaseOnce::Interrupted() {  }