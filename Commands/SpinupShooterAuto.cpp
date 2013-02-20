#include "SpinupShooterAuto.h"

SpinupShooterAuto::SpinupShooterAuto(float speed, float timeout) :
    setSpeed(speed),
    m_timeout(timeout)
{

}

// Called just before this Command runs the first time
void SpinupShooterAuto::Initialize() 
{
    s_Shooter->SetSpeed((setSpeed - 1 ) / 2);
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
    //s_Shooter->SetAbsoluteTolerance(kShooterSpinupTolerance);
	//s_Shooter->SetSetpoint(kShooterSpinupSpeed);
}

// Called repeatedly when this Command is scheduled to run
void SpinupShooterAuto::Execute() 
{

}

// Make this return true when this Command no longer needs to run execute()
bool SpinupShooterAuto::IsFinished() 
{
    return TimeSinceInitialized() > m_timeout;
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
    //return s_Shooter->OnTarget();
}

// Called once after isFinished returns true
void SpinupShooterAuto::End() 
{
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
	//s_Shooter->SetSetpoint(kShooterIdleSpeed);
    s_Shooter->SetSpeed((setSpeed - 1 ) / 2);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinupShooterAuto::Interrupted() 
{
    this->End();
}
