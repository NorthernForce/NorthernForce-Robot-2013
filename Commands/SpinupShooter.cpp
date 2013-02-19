#include "SpinupShooter.h"

SpinupShooter::SpinupShooter(float speed) :
    setSpeed(speed)
{

}

// Called just before this Command runs the first time
void SpinupShooter::Initialize() 
{
    s_Shooter->SetSpeed((setSpeed - 1 ) / 2);
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
    //s_Shooter->SetAbsoluteTolerance(kShooterSpinupTolerance);
	//s_Shooter->SetSetpoint(kShooterSpinupSpeed);
}

// Called repeatedly when this Command is scheduled to run
void SpinupShooter::Execute() 
{

}

// Make this return true when this Command no longer needs to run execute()
bool SpinupShooter::IsFinished() 
{
    return TimeSinceInitialized() > 3.0;
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
    //return s_Shooter->OnTarget();
}

// Called once after isFinished returns true
void SpinupShooter::End() 
{
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
	//s_Shooter->SetSetpoint(kShooterIdleSpeed);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinupShooter::Interrupted() 
{
    End();
}
