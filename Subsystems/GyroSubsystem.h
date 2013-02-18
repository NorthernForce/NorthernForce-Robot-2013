#ifndef GYROSUBSYSTEM_H
#define GYROSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Library.h"
#include "../CommandBase.h"
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
	AnalogChannel m_gyroTempChannel;
	LogFile m_gyroLogFile;
	float m_channelCenter;
	AlphaBetaFilter<float> m_gyroFilter;
    bool m_loggingEnabled;
	void Update();
public:
	GyroSubsystem(int slot, int sensorChannel, int tempSensorChannel, float sensitivity = 0.007);
	void InitDefaultCommand();
	void SetSensitivity(float sensitivity);
	float GetAngle();
	void Reset();
	float GetRate();
	void DoStationaryCalibration(int samples);
    void EnableLogging();
    void DisableLogging();
};

#endif
