#include "Autonomous.h"
#include "Robot.h"

#include "Commands/WaitCommand.h"
#include "Commands\Intake\IntakeLock.h"
#include "Commands\Intake\IntakeWheel.h"
#include "Commands\Intake\IntakeDeploy.h"
#include "Commands\Lift\LiftToPosition.h"
Autonomous::Autonomous()
{
	AddSequential(new IntakeDeploy(true));
	AddParallel(new TestPathfinder());
	AddParallel(new LiftToPosition(true));
	
}
