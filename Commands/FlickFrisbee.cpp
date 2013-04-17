#include "FlickFrisbee.h"
#include "FlickFrisbeeForward.h"
#include "FlickFrisbeeReverse.h"

FlickFrisbee::FlickFrisbee() 
{
	AddSequential(new FlickFrisbeeForward());
	AddSequential(new FlickFrisbeeReverse());
}
