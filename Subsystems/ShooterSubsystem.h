#ifndef SHOOTERSUBSYSTEM_H
#define SHOOTERSUBSYSTEM_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Joseph
 */
class ShooterSubsystem: public PIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.01;
	static const double Ki = 0.0;
	static const double Kd = 0.0;

	CANJaguar m_shooterMotor;
    Counter m_shooterWheelLightSensor;
    // This is the time of the last reset of the counter
    UINT32 m_counterLastTime;
public:
	ShooterSubsystem();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
    void ResetCounter();
    void SetSpeed(float speed);
    float GetAvgSpeed();
	void Stop();
	void EnableMotor();
};

#endif
