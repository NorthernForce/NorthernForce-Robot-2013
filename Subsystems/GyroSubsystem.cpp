#include "GyroSubsystem.h"
#include "../Robotmap.h"

/**
 * @brief Constructs the Gyro subsystem.
 * @param slot The cRIO slot that the Analog module is in.
 * @param channel The analog channel on the analog module that the 
 * sensor output is in.
 * @param sensitivity The gyro sensitivity to set. 
 */
GyroSubsystem::GyroSubsystem(int slot, int channel, float sensitivity) : 
	Subsystem("GyroSubsystem"),
	m_gyroChannel(slot, channel)
{
	m_gyroChannel.SetAccumulatorDeadband(0);
	m_gyroSensor = new Gyro(&m_gyroChannel);
	m_gyroSensor->SetSensitivity(sensitivity);
	this->Reset();
}
    
/**
 * @brief Initializes the default command for the gyro subsystem.
 */
void GyroSubsystem::InitDefaultCommand() 
{
	
}

/**
 * @brief Sets the sensitivity of the Gyro sensor.
 * @param sensitivity A float, the value to set the sensitivity to.
 */
void GyroSubsystem::SetSensitivity(float sensitivity)
{
	m_gyroSensor->SetSensitivity(sensitivity);
}

/**
 * @brief Resets the gyro sensor to 0.
 */
void GyroSubsystem::Reset()
{
	m_gyroSensor->Reset();
}

/**
 * @brief Gets the angle that the gyro is reading.
 * @return A float, the angle from the gyro.
 */
float GyroSubsystem::GetAngle()
{
	//@TODO: Convert this value to something meaningful.
	return m_gyroSensor->GetAngle();
}
