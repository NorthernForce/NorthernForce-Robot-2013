#ifndef TURNTORELATIVEANGLE_H
#define TURNTORELATIVEANGLE_H

#include "../CommandBase.h"

class TurnToRelativeAngle: public CommandBase {
private:
	float m_targetAngle;
public:
	TurnToRelativeAngle(float angle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
