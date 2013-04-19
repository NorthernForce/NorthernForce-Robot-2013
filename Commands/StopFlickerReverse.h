#ifndef STOPFLICKERREVERSE_H
#define STOPFLICKERREVERSE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class StopFlickerReverse: public CommandBase {
public:
	StopFlickerReverse();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
