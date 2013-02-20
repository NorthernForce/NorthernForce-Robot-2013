#ifndef SPINUP_SHOOTER_AUTO_H
#define SPINUP_SHOOTER_AUTO_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Joseph
 */
class SpinupShooterAuto: public CommandBase {
private:
	float setSpeed;
	float m_timeout;
public:
	SpinupShooterAuto(float speed, float timeout);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
