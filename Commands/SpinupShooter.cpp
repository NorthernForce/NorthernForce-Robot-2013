#include "SpinupShooter.h"

SpinupShooter::SpinupShooter(float speed, bool joystickVal) :
    setSpeed(speed),
    joystickVal(joystickVal)
{
}

// Called just before this Command runs the first time
void SpinupShooter::Initialize() 
{
	if (SHOOTER_PID_ENABLE)
	{
		s_Shooter->SetSpeed(setSpeed);
	}
	else
	{
		s_Shooter->SetSpeed(joystickVal ? (setSpeed - 1 ) / 2 : -setSpeed);
	}
//	s_Shooter->SetSpeed(setSpeed);
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
    return true;
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
//    s_Shooter->SetSpeed((setSpeed - 1 ) / 2);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinupShooter::Interrupted() 
{
    this->End();
}
