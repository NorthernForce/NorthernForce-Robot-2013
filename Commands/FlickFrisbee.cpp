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
	s_Shooter->Flick(Relay::kReverse);
}

// Called repeatedly when this Command is scheduled to run
void FlickFrisbee::Execute() 
{
	if (TimeSinceInitialized() > 0.2)
	{
		s_Shooter->Flick(Relay::kForward);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool FlickFrisbee::IsFinished() 
{
	return TimeSinceInitialized() > 0.5;
}

// Called once after isFinished returns true
void FlickFrisbee::End() 
{
	s_Shooter->Flick(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlickFrisbee::Interrupted() 
{
	End();
}
