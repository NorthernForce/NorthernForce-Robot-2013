#ifndef DRIVETORELATIVEANGLE_H
#define DRIVETORELATIVEANGLE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class DriveToRelativeAngle: public CommandBase 
{
private:
	float m_angle;
public:
	DriveToRelativeAngle(float angle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
