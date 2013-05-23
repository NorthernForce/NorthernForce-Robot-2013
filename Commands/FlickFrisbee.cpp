#include "FlickFrisbee.h"
#include "FlickFrisbeeForward.h"
#include "FlickFrisbeeReverse.h"
#include "StopFlickerReverse.h"
#include "UnlockShooter.h"
#include "LockShooter.h"
#include "SpinupShooter.h"
#include "RampUpShooter.h"
#include "WaitForRamp.h"

FlickFrisbee::FlickFrisbee(bool ramp, float speed, float angle) 
{
	AddSequential(new FlickFrisbeeForward());
	AddSequential(new FlickFrisbeeReverse());
	if (!SHOOTER_PID_ENABLE && ramp) { AddSequential(new RampUpShooter(speed, angle)); }
	if (SHOOTER_PID_ENABLE) { AddSequential(new WaitForRamp()); }
}
