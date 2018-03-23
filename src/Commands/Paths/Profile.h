#pragma once
#pragma once
namespace DriveProfile {
	const double WHEELBASE_WIDTH       = 0.6033;
	const double WHEEL_CIRCUMFERENCE   = 0.4878;
	const double MAX_VELOCITY          = 2.1;
	const double MAX_ACCELERATION      = 2;
	const double MAX_JERK              = 40;
	const double ENCODER_TICKS_PER_REV = 20;
	const double GEAR_RATIO            = 0.093457;

	const double TICKS_PER_REV         = WHEEL_CIRCUMFERENCE * GEAR_RATIO;
}
