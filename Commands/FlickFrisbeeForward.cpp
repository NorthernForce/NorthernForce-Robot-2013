#include "FlickFrisbeeForward.h"

FlickFrisbeeForward::FlickFrisbeeForward() 
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void FlickFrisbeeForward::Initialize() 
{
	s_Flicker->Forward();
}

// Called repeatedly when this Command is scheduled to run
void FlickFrisbeeForward::Execute() 
{
	
}

// Make this return true when this Command no longer needs to run execute()
bool FlickFrisbeeForward::IsFinished() 
{
	return s_Flicker->GetForwardLimit() || TimeSinceInitialized() > 0.15;
}

// Called once after isFinished returns true
void FlickFrisbeeForward::End() 
{
	s_Flicker->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlickFrisbeeForward::Interrupted() 
{
	End();
}
