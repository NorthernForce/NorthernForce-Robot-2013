#include "FlickFrisbee.h"
#include "FlickFrisbeeForward.h"
#include "FlickFrisbeeReverse.h"
#include "StopFlickerReverse.h"
#include "UnlockShooter.h"
#include "LockShooter.h"
#include "SpinupShooter.h"
#include "PrepareShooter.h"
#include "RampUpShooter.h"

FlickFrisbee::FlickFrisbee(bool ramp, float speed, float angle) 
{
	AddSequential(new FlickFrisbeeForward());
	AddSequential(new FlickFrisbeeReverse());
	if (!SHOOTER_PID_ENABLE && ramp) { AddSequential(new RampUpShooter(speed, angle)); }
}
