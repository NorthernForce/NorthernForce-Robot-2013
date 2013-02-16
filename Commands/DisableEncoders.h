#ifndef DISABLEENCODERS_H
#define DISABLEENCODERS_H

#include "../CommandBase.h"

class DisableEncoders: public CommandBase {
public:
	DisableEncoders();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
