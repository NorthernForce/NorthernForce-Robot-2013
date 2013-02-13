#include "GyroSubsystem.h"

/**
 * @brief Constructs the Gyro subsystem.
 * @param slot The cRIO slot that the Analog module is in.
 * @param channel The analog channel on the analog module that the 
 * sensor output is in.
 * @param sensitivity The gyro sensitivity to set. 
 */
GyroSubsystem::GyroSubsystem(int slot, int channel, float sensitivity) : 
	Subsystem("GyroSubsystem"),
	m_gyroChannel(slot, channel),
	m_gyroLogFile("GyroLog.txt")
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
 * @brief Gets the angle that the gyro is reading,
 * and writes it to a log file.
 * @return A float, the angle from the gyro.
 */
float GyroSubsystem::GetAngle()
{
	float angle = m_gyroSensor->GetAngle();
	char _tmp[32];
	sprintf(_tmp, "Angle: %f", angle);
	m_gyroLogFile.Write(_tmp);
	return angle;
}

/**
 * @brief Gets the rate from the gyro sensor, 
 * and writes it to a log file.
 * @return A float, the voltage (rate).
 */
float GyroSubsystem::GetRate()
{
	float voltage = m_gyroChannel.GetVoltage() - m_channelCenter;
	char _tmp[32];
	sprintf(_tmp, "Voltage: %f", voltage);
	m_gyroLogFile.Write(_tmp);
	return -0.55*voltage;
}

/**
 * @brief Completes a stationary calibration for the gyro
 * sensor.
 * @param samples The number of samples to take for calibration.
 */
void GyroSubsystem::DoStationaryCalibration(int samples)
{
	CommandBase::s_Log->LogMessage("Beginning stationary Gyro calibration...");
	float _accumulator = 0;
	for (int i = 0; i < samples; i++)
		_accumulator += m_gyroChannel.GetVoltage();
	
	m_channelCenter = _accumulator / samples;
	
	char* _tmp;
	sprintf(_tmp, "Gyro centered at %f", m_channelCenter);
	CommandBase::s_Log->LogMessage(_tmp);
}
