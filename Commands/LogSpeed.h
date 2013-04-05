#ifndef LOGSPEED_H
#define LOGSPEED_H

#include "../CommandBase.h"

class LogSpeed: public CommandBase {
private:
    int c;
public:
	LogSpeed();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
