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
	double deltaDistance;
	
	theta = s_Gyro->GetAngle();
//TODO: Get Optical Encoder Value for distance
	distance = m_Distance + 10;  // This is for stub, need Encoder Values converted to inches
	deltaDistance = distance - m_Distance;
	m_Distance = distance;
	
	s_Nav->propagate(GetFPGATime(), deltaDistance, theta);	
	
}

// Make this return true when this Command no longer needs to run execute()
bool UpdateNav::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void UpdateNav::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdateNav::Interrupted() 
{
	
}
