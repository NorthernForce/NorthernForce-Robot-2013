#include "ElevateShooterRelative.h"

ElevateShooterRelative::ElevateShooterRelative(float deltaAngle) : deltaAngle(deltaAngle) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(s_ShooterElevator);
}

// Called just before this Command runs the first time
void ElevateShooterRelative::Initialize() {
	s_ShooterElevator->SetPositionRelative(deltaAngle);
}

// Called repeatedly when this Command is scheduled to run
void ElevateShooterRelative::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ElevateShooterRelative::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ElevateShooterRelative::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevateShooterRelative::Interrupted() {
}
