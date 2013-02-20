#include "DriveToAngle.h"
#include "../Robotmap.h"

DriveToAngle::DriveToAngle(float angle) :
	m_angle(angle)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(s_Drive);
	Requires(s_Gyro);
}

// Called just before this Command runs the first time
void DriveToAngle::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void DriveToAngle::Execute() 
{
	if (m_angle < s_Gyro->GetAngle())
		s_Drive->DriveRobot(0, 0.1);
	else if (m_angle < s_Gyro->GetAngle())
		s_Drive->DriveRobot(0, -0.1);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToAngle::IsFinished() 
{
	return WithinTolerance(s_Gyro->GetAngle(), m_angle, 1);
}

// Called once after isFinished returns true
void DriveToAngle::End() 
{
	s_Drive->DriveRobot(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToAngle::Interrupted() 
{
	this->End();
}
