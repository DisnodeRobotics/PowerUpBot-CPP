#include "Autonomous.h"
#include "Robot.h"

#include "Commands/WaitCommand.h"



Autonomous::Autonomous()
{
	AddSequential(new TestPathfinder());
}
