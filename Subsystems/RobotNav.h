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
	double m_Theta;

public:
	RobotNav();
	RobotNav(float CurrentX, float CurrentY, double Theta);
	void InitDefaultCommand();
	void propagate(unsigned int time, float deltaX, float deltaY, double deltaTheta);
	//void propagate(unsigned int time, double deltaDistance, double deltaTheta);
	void propagate(unsigned int time, float deltaDistance, double Theta);
	void reset(unsigned int time, float x, float y, double theta);
	float GetX();
	float GetY();
	double GetTheta();

};

#endif
