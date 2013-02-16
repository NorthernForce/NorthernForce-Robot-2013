#ifndef ENABLEGYRO_H
#define ENABLEGYRO_H

#include "../CommandBase.h"

class EnableGyro: public CommandBase {
public:
	EnableGyro();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
