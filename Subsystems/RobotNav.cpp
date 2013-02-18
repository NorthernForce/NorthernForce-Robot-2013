#include "RobotNav.h"
#include "../Robotmap.h"
#include "math.h"
#include "../Commands/UpdateNav.h"

RobotNav::RobotNav() : Subsystem("RobotNav") 
{
	m_Time     = GetFPGATime();
//TODO: getx from smart-dashboard 	
	m_CurrentX = 0; 
//TODO: get y from smart-dashboard
    m_CurrentY = 0;
//TODO: get theta from smart-dashboard    
    m_Theta    = 0;
    
}


RobotNav::RobotNav(float CurrentX, float CurrentY, float Theta) : Subsystem("RobotNav")
{
	m_Time     = GetFPGATime();
	m_CurrentX = CurrentX;
	m_CurrentY = CurrentY;
	m_Theta    = Theta;
}
    


void RobotNav::InitDefaultCommand() 
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new UpdateNav());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void RobotNav::propagate(unsigned int time, float deltaX, float deltaY, float deltaTheta)
{
	m_Time = time;
	m_CurrentX = m_CurrentX + deltaX;
	m_CurrentY = m_CurrentY + deltaY;
	m_Theta    = m_Theta + deltaTheta;
	
}



void RobotNav::propagate(unsigned int time, float deltaDistance, float Theta)
{
	
	m_Time = time;
	m_Theta = Theta;
	m_CurrentX = m_CurrentX + ( deltaDistance * cos(m_Theta));
	m_CurrentY = m_CurrentY + (deltaDistance * sin(m_Theta));
	
	
}



void RobotNav::reset(unsigned int time, float x, float y, float theta)
{
	m_Time 		= time;
	m_CurrentX  = x;
	m_CurrentY  = y;
	m_Theta     = theta;
	
}

float RobotNav::GetX() 
{
	return m_CurrentX;
}
float RobotNav::GetY()
{
	return m_CurrentY;
}

float RobotNav::GetTheta()
{
	return m_Theta;
}			

