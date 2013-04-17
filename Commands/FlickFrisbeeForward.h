#ifndef FLICKFRISBEEFORWARD_H
#define FLICKFRISBEEFORWARD_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Arthur Lockman
 */
class FlickFrisbeeForward: public CommandBase {
public:
	FlickFrisbeeForward();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
