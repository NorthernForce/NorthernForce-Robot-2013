#ifndef TURNTORELATIVEANGLE_H
#define TURNTORELATIVEANGLE_H

#include "../CommandBase.h"

class TurnToRelativeAngle: public CommandBase {
private:
	float m_targetAngle;
    float m_integral;
    float (*m_method)();
public:
	TurnToRelativeAngle(float angle);
    TurnToRelativeAngle(float (*method)());
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
