#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include <CANJaguar.h>
#include <Relay.h>
#include <Counter.h>
#include <AnalogModule.h>
#include "../Library.h"

/**
 * This is the class which controls the driving of the robot. This
 * is a subsystem, and behaves just like every other subsystem
 * in the code library. Rather than using a different class
 * for drive like last year, it is better to contain it all
 * inside this one class. 
 * 
 * @author arthurlockman
 */
class ShooterSubsystem: public Subsystem 
{
private:
	CANJaguar m_shooterMotor;
    Relay m_shooterFlicker;
    Relay m_shooterElevatorMotor;
    AnalogChannel m_elevationPotentiometer;
    Counter m_shooterWheelLightSensor;
    // This is the time of the last reset of the counter
    UINT32 m_counterLastTime;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
    void SetShooterSpeed(float speed);
    void Flick(bool extend);
    void ResetCounter();
    float GetAvgSpeed();
	void Stop();
	void EnableMotor();
};

#endif
