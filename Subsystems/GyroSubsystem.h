#ifndef GYROSUBSYSTEM_H
#define GYROSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * A subsystem for accessing the data from the Gyro subsystem.
 *
 * @author arthurlockman
 */
class GyroSubsystem: public Subsystem 
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Gyro *m_gyroSensor;
	AnalogChannel m_gyroChannel;
public:
	GyroSubsystem(int slot, int channel, float sensitivity = 0.05);
	void InitDefaultCommand();
	void SetSensitivity(float sensitivity);
	float GetAngle();
	void Reset();
};

#endif
