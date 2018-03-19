#pragma once
#pragma once
namespace DriveProfile {
	const double WHEELBASE_WIDTH       = 0.6;
	const double WHEEL_CIRCUMFERENCE   = 18.49;
	const double MAX_VELOCITY          = 5;
	const double ENCODER_TICKS_PER_REV = 40;
	const double GEAR_RATIO            = 0.107;
	const double TICKS_PER_REV         = ENCODER_TICKS_PER_REV * GEAR_RATIO;
}
