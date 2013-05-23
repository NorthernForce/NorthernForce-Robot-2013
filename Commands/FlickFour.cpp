#include "FlickFour.h"
#include "FlickFrisbee.h"
#include "UnlockShooter.h"
#include "LockShooter.h"
#include "RampUpShooter.h"

FlickFour::FlickFour(float shotSpeed, float shotAngle) 
{
	AddSequential(new UnlockShooter());
	AddSequential(new FlickFrisbee(false));
	AddSequential(new FlickFrisbee(false));
	AddSequential(new FlickFrisbee(false));
	AddSequential(new FlickFrisbee(false));
	Wait(1.0);
	AddSequential(new LockShooter());
}
