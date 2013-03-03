#include "StopShooter.h"

StopShooter::StopShooter()
{
}

// Called just before this Command runs the first time
void StopShooter::Initialize() 
{
    s_Shooter->Stop();
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
    //s_Shooter->SetAbsoluteTolerance(kShooterStopTolerance);
	//s_Shooter->SetSetpoint(kShooterStopSpeed);
}

// Called repeatedly when this Command is scheduled to run
void StopShooter::Execute() 
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopShooter::IsFinished() 
{
    return true;
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
    //return s_Shooter->OnTarget();
}

// Called once after isFinished returns true
void StopShooter::End() 
{
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
	//s_Shooter->SetSetpoint(kShooterIdleSpeed);
    s_Shooter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopShooter::Interrupted() 
{
    this->End();
}
