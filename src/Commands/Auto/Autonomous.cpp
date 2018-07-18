#include "Autonomous.h"
#include "Robot.h"
#include "Sequences/Path_CenterToSwitch.h"
#include "Sequences/Path_LeftToSwitch.h"
#include "Sequences/Path_RightToSwitch.h"
#include "Commands/WaitCommand.h"
#include "Commands\Intake\IntakeLock.h"
#include "Commands\Intake\IntakeWheel.h"
#include "Commands\Intake\IntakeDeploy.h"
#include "Commands\Lift\LiftToPosition.h"
Autonomous::Autonomous()
{
	
	
	
	AddSequential(new Path_LeftToSwitch());
	
	
	if (DriverStation::GetInstance().GetGameSpecificMessage()[0] == 'L'){
		AddSequential(new IntakeWheel(-1.0));
	}
	

}
