#ifndef DRIVETO_H
#define DRIVETO_H

#include "../CommandBase.h"
#include <math.h>
#include "../Subsystems/RobotNav.h"
#include "../Subsystems/DriveSubsystem.h"

/**
 *
 *
 * @author jcrosby
 */
class DriveTo: public CommandBase {
public:
	DriveTo(float x, float y);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
	
private:
	void UpdatePos();
	void CalcVector();
	double absval(double val);
	
	float m_CurrentX;
	float m_CurrentY;
	
	double m_Distance;
	float m_Theta;
	
	float m_EndX;
	float m_EndY;
	float m_EndTheta;
	
};

#endif
