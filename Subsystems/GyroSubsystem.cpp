#include "GyroSubsystem.h"

/**
 * @brief Constructs the Gyro subsystem.
 * @param slot The cRIO slot that the Analog module is in.
 * @param sensorChannel The analog channel on the analog module that the 
 * gyro sensor output is in.
 * @param tempSensorChannel The analog channel on the analog module that the 
 * gyro's temperature sensor output is in.
 * @param sensitivity The gyro sensitivity to set. 
 */
GyroSubsystem::GyroSubsystem(int slot, int sensorChannel, int tempSensorChannel, float sensitivity) : 
	Subsystem("GyroSubsystem"),
	m_gyroChannel(slot, sensorChannel),
	m_gyroTempChannel(slot, tempSensorChannel),
	m_gyroLogFile("GyroLog.txt"),
	m_gyroFilter(0.1, 0.005),
    m_loggingEnabled(false)
{
	m_gyroChannel.SetAccumulatorDeadband(0);
	m_gyroTempChannel.SetAccumulatorCenter(0);
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
	m_gyroFilter.Clear();
}

/**
 * @brief Gets the angle that the gyro is reading,
 * and writes it to a log file.
 * @return A float, the angle from the gyro.
 */
float GyroSubsystem::GetAngle()
{
	float angle = m_gyroSensor->GetAngle();
    if(m_loggingEnabled) {
        char _tmp[32];
        sprintf(_tmp, "Angle: %f", angle);
        m_gyroLogFile.Write(_tmp);
    }
	return -angle;
}

/**
 * @brief Gets the rate from the gyro sensor, 
 * and writes it to a log file.
 * @return A float, the voltage (rate).
 */
float GyroSubsystem::GetRate()
{
	this->Update();
	float voltage = m_gyroFilter.GetValue();
	char _tmp[100];
	sprintf(_tmp, "Voltage: %f", voltage);
	//m_gyroLogFile.Write(_tmp);
	return 0.55*voltage;
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
	this->Reset();
}

/**
 * @brief Updates the gyro values in the filter. 
 */
void GyroSubsystem::Update()
{
	float voltage = 0.55 * (m_gyroChannel.GetVoltage() - m_channelCenter);
	m_gyroFilter.Update(voltage, GetFPGATime());
}

void GyroSubsystem::EnableLogging() { m_loggingEnabled = true; }
void GyroSubsystem::DisableLogging() { m_loggingEnabled = false; }
