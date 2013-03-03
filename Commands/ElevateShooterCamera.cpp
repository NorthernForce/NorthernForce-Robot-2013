#include "ElevateShooterCamera.h"

ElevateShooterCamera::ElevateShooterCamera() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(s_ShooterElevator);
}

// Called just before this Command runs the first time
void ElevateShooterCamera::Initialize() {
    float target = -s_SockClient->GetLastVertAngle() - 2.0;
    printf("[Camera] Elevating to %f\n", target);
	s_ShooterElevator->SetPositionRelative(target);
}

// Called repeatedly when this Command is scheduled to run
void ElevateShooterCamera::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ElevateShooterCamera::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ElevateShooterCamera::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevateShooterCamera::Interrupted() {
}
