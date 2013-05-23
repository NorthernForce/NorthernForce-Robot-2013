#include "WaitForRamp.h"

WaitForRamp::WaitForRamp() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void WaitForRamp::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void WaitForRamp::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool WaitForRamp::IsFinished() {
	return WithinTolerance(s_Shooter->GetSpeed(), s_Shooter->GetSetpoint(), 50.0);
}

// Called once after isFinished returns true
void WaitForRamp::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForRamp::Interrupted() {
}
