#include "FlickFour.h"
#include "FlickFrisbee.h"
#include "UnlockShooter.h"
#include "LockShooter.h"
#include "RampUpShooter.h"

FlickFour::FlickFour(float shotSpeed, float shotAngle) 
{
	AddSequential(new UnlockShooter());
//	AddSequential(new RampUpShooter(shotSpeed, shotAngle));
	AddSequential(new FlickFrisbee(true, shotSpeed, shotAngle));
	AddSequential(new FlickFrisbee(true, shotSpeed, shotAngle));
	AddSequential(new FlickFrisbee(true, shotSpeed, shotAngle));
	AddSequential(new FlickFrisbee(true, shotSpeed, shotAngle));
	AddSequential(new LockShooter());
}
