#ifndef RAMPUPSHOOTER_H
#define RAMPUPSHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class RampUpShooter: public CommandBase {
private:
	float kEndSpeed;
	float kEndAngle;
public:
	RampUpShooter(float endSpeed, float endAngle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
