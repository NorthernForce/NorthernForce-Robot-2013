#ifndef WAITFORRAMP_H
#define WAITFORRAMP_H

#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class WaitForRamp: public CommandBase {
public:
	WaitForRamp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
