#ifndef ELEVATESHOOTERRELATIVE_H
#define ELEVATESHOOTERRELATIVE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class ElevateShooterRelative: public CommandBase {
private:
	float deltaAngle;
public:
	ElevateShooterRelative(float deltaAngle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
