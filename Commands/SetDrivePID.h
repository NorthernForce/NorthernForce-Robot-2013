#ifndef SETDRIVEPID_H
#define SETDRIVEPID_H

#include "../CommandBase.h"

/**
 * Change the PID values on the drive system.
 *
 * @author Joseph Martin
 */
class SetDrivePID: public CommandBase {
public:
	SetDrivePID();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
