#include "DriveTo.h"


DriveTo::DriveTo(float x, float y) 
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(s_Nav);
	Requires(s_Drive);
	
	m_EndX = x;
	m_EndY = y;
	
}

// Called just before this Command runs the first time
void DriveTo::Initialize() 
{
	UpdatePos();
}

// Called repeatedly when this Command is scheduled to run
void DriveTo::Execute() 
{
	float angularRate = 0;
	float speed = 0;
	float theta = m_Theta;
	
	UpdatePos();
	CalcVector();

//TODO: Determine Speed & Check Angular Measurement
	if (absval(m_Theta - theta) <= kDistanceBand)
			angularRate = 0.0;
	else angularRate = 0.1;
	
	if (m_Distance <= (2 * kDistanceBand))
			speed = 0.1;
	else speed = 0.3;
	
	s_Drive->DriveRobot(speed, angularRate);
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTo::IsFinished() 
{
	if ( absval(m_Distance) <= kDistanceBand )
				return(true);		
	else 
      return(false);
}

// Called once after isFinished returns true
void DriveTo::End() 
{
//TODO: Validate that Change in angle moves robot with no speed set?
	s_Drive->DriveRobot(0.0, m_EndTheta);
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTo::Interrupted() 
{
	
}


void DriveTo::CalcVector() 
{
	float deltaX = m_EndX - m_CurrentX;
	float deltaY = m_EndY - m_CurrentY;
	
	m_Distance = sqrt( (deltaX * deltaX) + (deltaY * deltaY) );
	m_Theta = atan( deltaX / deltaY );
	
}


void DriveTo::UpdatePos() 
{
	m_CurrentX = s_Nav->GetX();
	m_CurrentY = s_Nav->GetY();
	
}

double DriveTo::absval(double val)
{
	if (val < 0)
	  return -val;
	else 
      return val;
}
