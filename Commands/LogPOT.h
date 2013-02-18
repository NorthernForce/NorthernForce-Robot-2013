#ifndef LOGPOT_H
#define LOGPOT_H

#include "../CommandBase.h"

class LogPOT: public CommandBase {
public:
	LogPOT();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
