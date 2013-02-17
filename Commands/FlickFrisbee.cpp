#include "FlickFrisbee.h"

FlickFrisbee::FlickFrisbee() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(s_Shooter);
}

// Called just before this Command runs the first time
void FlickFrisbee::Initialize() {
	s_Shooter->Flick(true);
}

// Called repeatedly when this Command is scheduled to run
void FlickFrisbee::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool FlickFrisbee::IsFinished() {
	return TimeSinceInitialized() > 0.5;
}

// Called once after isFinished returns true
void FlickFrisbee::End() {
	s_Shooter->Flick(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlickFrisbee::Interrupted() {
	End();
}
