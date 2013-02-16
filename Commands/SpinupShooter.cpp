#include "SpinupShooter.h"

SpinupShooter::SpinupShooter() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
    Requires(s_Shooter);
}

// Called just before this Command runs the first time
void SpinupShooter::Initialize() {
    s_Shooter->SetAbsoluteTolerance(kShooterSpinupTolerance);
	s_Shooter->SetSetpoint(kShooterSpinupSpeed);
}

// Called repeatedly when this Command is scheduled to run
void SpinupShooter::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool SpinupShooter::IsFinished() {
    return s_Shooter->OnTarget();
}

// Called once after isFinished returns true
void SpinupShooter::End() {
	s_Shooter->SetSetpoint(kShooterIdleSpeed);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinupShooter::Interrupted() {
    End();
}
