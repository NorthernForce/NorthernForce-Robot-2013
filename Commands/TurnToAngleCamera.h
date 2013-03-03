#ifndef TURNTOANGLECAMERA_H
#define TURNTOANGLECAMERA_H

#include "../CommandBase.h"

class TurnToAngleCamera: public CommandBase {
private:
	float m_targetAngle;
    float m_integral;
public:
	TurnToAngleCamera();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
