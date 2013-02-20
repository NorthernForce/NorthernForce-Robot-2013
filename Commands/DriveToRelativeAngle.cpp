#include "DriveToRelativeAngle.h"
#include "../Robotmap.h"

DriveToRelativeAngle::DriveToRelativeAngle(float angle) :
	m_angle(angle) 
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(s_Drive);
	Requires(s_Gyro);
}

// Called just before this Command runs the first time
void DriveToRelativeAngle::Initialize() 
{
	m_angle += s_Gyro->GetAngle();
	printf("Turining to angle %f\n", m_angle);
}

// Called repeatedly when this Command is scheduled to run
void DriveToRelativeAngle::Execute() 
{
	while (!WithinTolerance(s_Gyro->GetAngle(), m_angle, 3))
		s_Drive->DriveRobot(0.0, (.05 * (m_angle - s_Gyro->GetAngle())));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToRelativeAngle::IsFinished() 
{
	return WithinTolerance(s_Gyro->GetAngle(), m_angle, 3);
}

// Called once after isFinished returns true
void DriveToRelativeAngle::End() 
{
	s_Drive->DriveRobot(0.0, 0.0);
	printf("Finished, at angle %f.\n", m_angle);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToRelativeAngle::Interrupted() 
{
	this->End();
}
