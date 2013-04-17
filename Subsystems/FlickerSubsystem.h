#ifndef FLICKERSUBSYSTEM_H
#define FLICKERSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * A subsystem to control the new frisbee flicker.
 *
 * @author arthurlockman
 */
class FlickerSubsystem: public Subsystem {
private:
	DigitalInput m_rearLimit;
	DigitalInput m_forwardLimit;
	Victor m_flickerVictor;
	Relay m_lock;
public:
	FlickerSubsystem();
	void InitDefaultCommand();
	void Forward();
	void Reverse();
	void Stop();
	void Unlock();
	void Lock();
	bool GetForwardLimit();
	bool GetRearLimit();
};

#endif
