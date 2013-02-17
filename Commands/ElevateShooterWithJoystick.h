#ifndef ELEVATE_SHOOTER_WITH_JOYSTICK_H_
#define ELEVATE_SHOOTER_WITH_JOYSTICK_H_

#include "../CommandBase.h"

/**
 * Drive the robot with an XBox Joystick.
 *
 * @author Joseph Martin
 */
class ElevateShooterWithJoystick: public CommandBase {
public:
	ElevateShooterWithJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
