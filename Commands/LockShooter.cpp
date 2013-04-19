#include "LockShooter.h"

LockShooter::LockShooter()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LockShooter::Initialize() 
{
	s_Flicker->Lock();
}

// Called repeatedly when this Command is scheduled to run
void LockShooter::Execute() 
{
	
}

// Make this return true when this Command no longer needs to run execute()
bool LockShooter::IsFinished() 
{
	return true;
}

// Called once after isFinished returns true
void LockShooter::End() 
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LockShooter::Interrupted() 
{
}
