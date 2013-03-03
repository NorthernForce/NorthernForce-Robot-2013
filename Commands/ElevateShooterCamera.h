#ifndef ELEVATESHOOTERCAMERA_H
#define ELEVATESHOOTERCAMERA_H

#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class ElevateShooterCamera: public CommandBase {
private:
public:
	ElevateShooterCamera();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
