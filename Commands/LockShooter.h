#ifndef LOCKSHOOTER_H
#define LOCKSHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class LockShooter: public CommandBase {
public:
	LockShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
