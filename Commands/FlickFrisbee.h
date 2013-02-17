#ifndef FLICKFRISBEE_H
#define FLICKFRISBEE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Joseph
 */
class FlickFrisbee: public CommandBase {
public:
	FlickFrisbee();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
