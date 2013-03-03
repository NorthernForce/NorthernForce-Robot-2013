#include "SpinShooter.h"

SpinShooter::SpinShooter(float speed, bool joystickVal) :
    setSpeed(speed),
    joystickVal(joystickVal)
{
}

// Called just before this Command runs the first time
void SpinShooter::Initialize() 
{
    s_Shooter->SetSpeed(joystickVal ? (setSpeed - 1 ) / 2 : -setSpeed);
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
    //s_Shooter->SetAbsoluteTolerance(kShooterSpinTolerance);
	//s_Shooter->SetSetpoint(kShooterSpinSpeed);
}

// Called repeatedly when this Command is scheduled to run
void SpinShooter::Execute() 
{

}

// Make this return true when this Command no longer needs to run execute()
bool SpinShooter::IsFinished() 
{
    return false;
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
    //return s_Shooter->OnTarget();
}

// Called once after isFinished returns true
void SpinShooter::End() 
{
    // Not using PID loop because we don't have a way
    // of measuring the shooter wheel speed yet.
	//s_Shooter->SetSetpoint(kShooterIdleSpeed);
    s_Shooter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinShooter::Interrupted() 
{
    this->End();
}
