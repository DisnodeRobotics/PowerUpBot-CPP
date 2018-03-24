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
	
	
	
	std::string msg = DriverStation::GetInstance().GetGameSpecificMessage();
	//int pos = 1;
	int pos  = (int)SmartDashboard::GetNumber("auto_pos", 1);

	AddSequential(new IntakeDeploy(true));
	AddParallel(new LiftToPosition(true));
	switch (pos) {
		case 1:
			AddSequential(new Path_LeftToSwitch());

			if (msg[0] == 'L') {
				AddSequential(new IntakeWheel(-1));
			}
		break;

		case 2:
			AddSequential(new Path_CenterToSwitch());
			AddSequential(new IntakeWheel(-1));
			break;

		case 3:
			AddSequential(new Path_RightToSwitch());
			if (msg[0] == 'R') {
				AddSequential(new IntakeWheel(-1));
			}
			break;
	}
	
	

	

}
