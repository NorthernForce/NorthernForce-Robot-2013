#include "SpinupShooterWithJoystick.h"

SpinupShooterWithJoystick::SpinupShooterWithJoystick() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
    Requires(s_Shooter);
}

// Called just before this Command runs the first time
void SpinupShooterWithJoystick::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void SpinupShooterWithJoystick::Execute() {
	s_Shooter->SetSpeed((oi->GetManipulatorStick().GetPOT() - 1 ) / 2);
}

// Make this return true when this Command no longer needs to run execute()
bool SpinupShooterWithJoystick::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void SpinupShooterWithJoystick::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinupShooterWithJoystick::Interrupted() {
    End();
}
