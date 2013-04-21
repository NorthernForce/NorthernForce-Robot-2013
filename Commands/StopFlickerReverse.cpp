#include "StopFlickerReverse.h"

StopFlickerReverse::StopFlickerReverse() 
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void StopFlickerReverse::Initialize() 
{
	s_Flicker->Forward(0.15);
}

// Called repeatedly when this Command is scheduled to run
void StopFlickerReverse::Execute() 
{
	//Do nothing.
}

// Make this return true when this Command no longer needs to run execute()
bool StopFlickerReverse::IsFinished() 
{
	return TimeSinceInitialized() > 0.015;
}

// Called once after isFinished returns true
void StopFlickerReverse::End()
{
	s_Flicker->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopFlickerReverse::Interrupted() 
{
	End();
}
