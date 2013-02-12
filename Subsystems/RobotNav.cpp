#include "RobotNav.h"
#include "../Robotmap.h"
#include "math.h"

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


RobotNav::RobotNav(double CurrentX, double CurrentY, double Theta) : Subsystem("RobotNav")
{
	m_Time     = GetFPGATime();
	m_CurrentX = CurrentX;
	m_CurrentY = CurrentY;
	m_Theta    = Theta;
}
    


void RobotNav::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void RobotNav::propagate(unsigned int time, double deltaX, double deltaY, double deltaTheta)
{
	m_Time = time;
	m_CurrentX = m_CurrentX + deltaX;
	m_CurrentY = m_CurrentY + deltaY;
	m_Theta    = m_Theta + deltaTheta;
	
}


void RobotNav::propagate(unsigned int time, double deltaDistance, double deltaTheta)
{
	
	m_Time = time;
	m_Theta = m_Theta + deltaTheta;
	m_CurrentX = m_CurrentX + ( deltaDistance * cos(m_Theta));
	m_CurrentY = m_CurrentY + (deltaDistance * sin(m_Theta));
	
	
}


void RobotNav::reset(unsigned int time, double x, double y, double theta)
{
	m_Time = time;
	m_CurrentX    = x;
	m_CurrentY    = y;
	m_Theta = theta;
	
}

double RobotNav::GetX() 
{
	return m_CurrentX;
}
double RobotNav::GetY()
{
	return m_CurrentY;
}

double RobotNav::GetTheta()
{
	return m_Theta;
}			

