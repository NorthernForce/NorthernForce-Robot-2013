#include "FlickFrisbee.h"
#include "FlickFrisbeeForward.h"
#include "FlickFrisbeeReverse.h"
#include "StopFlickerReverse.h"

FlickFrisbee::FlickFrisbee() 
{
	AddSequential(new FlickFrisbeeForward());
	AddSequential(new FlickFrisbeeReverse());
	AddSequential(new StopFlickerReverse());
}
