#ifndef ENABLEENCODERS_H
#define ENABLEENCODERS_H

#include "../CommandBase.h"

class EnableEncoders: public CommandBase {
public:
	EnableEncoders();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
