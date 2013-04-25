#include "FlickFrisbeeReverse.h"

FlickFrisbeeReverse::FlickFrisbeeReverse() 
{
	
}

// Called just before this Command runs the first time
void FlickFrisbeeReverse::Initialize() 
{
	s_Flicker->Reverse();
}

// Called repeatedly when this Command is scheduled to run
void FlickFrisbeeReverse::Execute() 
{
	
}

// Make this return true when this Command no longer needs to run execute()
bool FlickFrisbeeReverse::IsFinished() 
{
	return s_Flicker->GetRearLimit() || TimeSinceInitialized() > 0.25;
}

// Called once after isFinished returns true
void FlickFrisbeeReverse::End() 
{
	s_Flicker->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlickFrisbeeReverse::Interrupted() 
{
	End();
}
