#include "PrepareShooter.h"
#include "SpinupShooter.h"
#include "ElevateShooter.h"

PrepareShooter::PrepareShooter(float speed, float angle)
{
    AddSequential(new SpinupShooter(speed));
    AddSequential(new ElevateShooter(angle));
}
