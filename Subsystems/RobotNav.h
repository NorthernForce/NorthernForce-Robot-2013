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
	double m_CurrentX;
	double m_CurrentY;
	double m_Theta;

public:
	RobotNav();
	RobotNav(double CurrentX, double CurrentY, double Theta);
	void InitDefaultCommand();
	void propagate(unsigned int time, double deltaX, double deltaY, double deltaTheta);
	//void propagate(unsigned int time, double deltaDistance, double deltaTheta);
	void propagate(unsigned int time, double deltaDistance, double Theta);
	void reset(unsigned int time, double x, double y, double theta);
	double GetX();
	double GetY();
	double GetTheta();

};

#endif
