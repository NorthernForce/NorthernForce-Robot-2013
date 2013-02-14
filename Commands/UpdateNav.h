#ifndef UPDATENAV_H
#define UPDATENAV_H

#include "../CommandBase.h"
#include "../Subsystems/RobotNav.h"
#include "../Subsystems/GyroSubsystem.h"
#include "../Subsystems/DriveSubsystem.h"



/**
 *
 *
 * @author jcrosby
 */
class UpdateNav: public CommandBase 
{
  public:
	UpdateNav();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
  private:
	double m_Distance;
	
	
};

#endif
