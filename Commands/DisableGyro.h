#ifndef DISABLEGYRO_H
#define DISABLEGYRO_H

#include "../CommandBase.h"

class DisableGyro: public CommandBase {
public:
	DisableGyro();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

};

#endif
