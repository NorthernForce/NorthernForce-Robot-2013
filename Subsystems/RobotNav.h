#ifndef ROBOTNAV_H
#define ROBOTNAV_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


/**
 * A navigation system for the robot. 
 *
 * @author jcrosby
 */
class RobotNav: public Subsystem {
private:
	unsigned int m_Time;
	float m_CurrentX;
	float m_CurrentY;
	float m_Theta;

public:
	RobotNav();
	RobotNav(float CurrentX, float CurrentY, float Theta);
	void InitDefaultCommand();
	void propagate(unsigned int time, float deltaX, float deltaY, float deltaTheta);
	//void propagate(unsigned int time, double deltaDistance, double deltaTheta);
	void propagate(unsigned int time, float deltaDistance, float Theta);
	void reset(unsigned int time, float x, float y, float theta);
	float GetX();
	float GetY();
	float GetTheta();

};

#endif
