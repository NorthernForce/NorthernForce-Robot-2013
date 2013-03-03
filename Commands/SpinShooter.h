#ifndef SPIN_SHOOTER_H
#define SPIN_SHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Joseph
 */
class SpinShooter: public CommandBase {
private:
	float setSpeed;
    bool joystickVal;
public:
	SpinShooter(float speed, bool joystickVal = true);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
