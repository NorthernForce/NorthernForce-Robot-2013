#include "RampUpShooter.h"

RampUpShooter::RampUpShooter(float endSpeed, float endAngle) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	kEndSpeed = endSpeed;
	kEndAngle = endAngle;
}

// Called just before this Command runs the first time
void RampUpShooter::Initialize() {
	s_Shooter->SetSpeed(-1.0);
	s_ShooterElevator->SetSetpoint((double)kEndAngle);
}

// Called repeatedly when this Command is scheduled to run
void RampUpShooter::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool RampUpShooter::IsFinished() {
	return s_Shooter->atTarget || (TimeSinceInitialized() > 2.0);
}

// Called once after isFinished returns true
void RampUpShooter::End() {
	s_Shooter->SetSpeed((kEndSpeed - 1 ) / 2);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RampUpShooter::Interrupted() {
}
