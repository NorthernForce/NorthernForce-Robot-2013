#ifndef DRIVETOANGLE_H
#define DRIVETOANGLE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class DriveToAngle: public CommandBase 
{
private:
	float m_angle;
public:
	DriveToAngle(float angle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
