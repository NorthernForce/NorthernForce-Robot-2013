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
	if (ramp) { AddSequential(new RampUpShooter(speed, angle)); }
//	AddSequential(new SpinupShooter(-1.0, false));
//	Wait(0.5);
//	AddSequential(new PrepareShooter(kPyramidBackSpeed, kPyramidBackAngle));
}
