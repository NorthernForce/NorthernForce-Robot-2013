#ifndef SPINUP_SHOOTER_WITH_JOYSTICK_H
#define SPINUP_SHOOTER_WITH_JOYSTICK_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Joseph
 */
class SpinupShooterWithJoystick: public CommandBase {
public:
	SpinupShooterWithJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
