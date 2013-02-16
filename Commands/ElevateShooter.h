#ifndef ELEVATE_SHOOTER_H_
#define ELEVATE_SHOOTER_H_

#include "../CommandBase.h"

/**
 * Drive the robot with an XBox Joystick.
 *
 * @author Joseph Martin
 */
class ElevateShooter: public CommandBase {
private:
	float targetAngle;
    float errorAccumulator;
public:
	ElevateShooter(float angle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
