#include "FlickFrisbee.h"
#include <Relay.h>

FlickFrisbee::FlickFrisbee() 
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void FlickFrisbee::Initialize() 
{
	s_Flicker->Forward();
}

// Called repeatedly when this Command is scheduled to run
void FlickFrisbee::Execute() 
{
	if (s_Flicker->GetForwardLimit() && TimeSinceInitialized() > 0.05)
		s_Flicker->Reverse();
}

// Make this return true when this Command no longer needs to run execute()
bool FlickFrisbee::IsFinished() 
{
	return s_Flicker->GetRearLimit();
}

// Called once after isFinished returns true
void FlickFrisbee::End() 
{
	s_Flicker->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlickFrisbee::Interrupted() 
{
	End();
}
