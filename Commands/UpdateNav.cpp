#include "UpdateNav.h"

UpdateNav::UpdateNav() 
{
	Requires(s_Nav);
	// Use requires() here to declare subsystem dependencies
	// eg. Requires(s_chassis);
}

// Called just before this Command runs the first time
void UpdateNav::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void UpdateNav::Execute() 
{
	float theta;
	double distance;
	float deltaDistanceInch;
	
//  Get Angle from Gyro
	theta = s_Gyro->GetAngle();
	
//  Get Average Distance from the Jaguars
	distance = s_Drive->GetAvgDistance();
	deltaDistanceInch = ( distance - m_DistanceEncoder ) * kWheelEncoderRatio;
	m_DistanceEncoder = distance;
	
	s_Nav->propagate(GetFPGATime(), deltaDistanceInch, theta);	
	
}

// Make this return true when this Command no longer needs to run execute()
bool UpdateNav::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void UpdateNav::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdateNav::Interrupted() 
{
	
}
