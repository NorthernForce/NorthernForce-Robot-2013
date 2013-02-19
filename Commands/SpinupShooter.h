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
public:
	SpinupShooter(float speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
