#ifndef FLICKFRISBEEREVERSE_H
#define FLICKFRISBEEREVERSE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Arthur Lockman
 */
class FlickFrisbeeReverse: public CommandBase {
public:
	FlickFrisbeeReverse();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
