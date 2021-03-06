#ifndef RAMPEDCANJAGUAR_H
#define RAMPEDCANJAGUAR_H

#include <WPILib.h>
#include <CANJaguar.h>
#include "../Library.h"

/*
 * @brief A class to control a Jaguar in a ramped mode, making
 * it safer to operate, and less stressful on the motor.
 * 
 * @author Joseph Martin
 */
class RampedCANJaguar : public CANJaguar 
{
private:
    float m_maxAcceleration;
    float m_maxVelocity;
    float m_tolerance;
    float m_thereTolerance;
    float m_prevTime;
    float m_prevPosition;
    float m_prevVelocity;
    float m_prevAccel;
    float m_ramp;
    static const float deltaT = 0.02;
    float Limit(float in, float max);
public:
    RampedCANJaguar(int deviceNumber, float maxVelocity, float maxAcceleration, float m_tolerance, float m_thereTolerance);
    void PrintLimits();
    void SetMaxAcceleration(float maxAcceleration);
    void SetMaxVelocity(float maxVelocity);
    void SetTolerance(float tolerance, float thereTolerance);
    void DisableControl();
    void EnableControl(float encoderInitialPosition);
    void EnableControl();
    void SetOutput(float outputValue);
    float Get();
};
#endif
