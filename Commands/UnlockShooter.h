#ifndef UNLOCKSHOOTER_H
#define UNLOCKSHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Arthur Lockman
 */
class UnlockShooter: public CommandBase {
public:
	UnlockShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
