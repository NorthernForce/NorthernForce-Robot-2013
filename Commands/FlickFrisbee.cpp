#include "FlickFrisbee.h"
#include "FlickFrisbeeForward.h"
#include "FlickFrisbeeReverse.h"
#include "StopFlickerReverse.h"
#include "UnlockShooter.h"
#include "LockShooter.h"

FlickFrisbee::FlickFrisbee() 
{
	AddSequential(new UnlockShooter());
	AddSequential(new FlickFrisbeeForward());
	AddSequential(new FlickFrisbeeReverse());
	AddSequential(new StopFlickerReverse());
	Wait(0.2);
	AddSequential(new LockShooter());
}
