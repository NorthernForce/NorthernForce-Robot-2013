#include "UnlockShooter.h"

UnlockShooter::UnlockShooter() 
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void UnlockShooter::Initialize() 
{
	s_Flicker->Unlock();
}

// Called repeatedly when this Command is scheduled to run
void UnlockShooter::Execute() 
{
	
}

// Make this return true when this Command no longer needs to run execute()
bool UnlockShooter::IsFinished() 
{
	return false;
}

// Called once after isFinished returns true
void UnlockShooter::End() 
{
	s_Flicker->Lock();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UnlockShooter::Interrupted() 
{
	End();
}
