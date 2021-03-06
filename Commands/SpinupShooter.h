#ifndef SPINUP_SHOOTER_H
#define SPINUP_SHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Joseph
 */
class SpinupShooter: public CommandBase {
private:
	float setSpeed;
    bool joystickVal;
public:
	SpinupShooter(float speed, bool joystickVal = true);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
