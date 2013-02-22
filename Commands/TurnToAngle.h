#ifndef DISABLEENCODERS_H
#define DISABLEENCODERS_H

#include "../CommandBase.h"

class TurnToAngle: public CommandBase {
private:
	float m_targetAngle;
public:
	TurnToAngle(float angle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
