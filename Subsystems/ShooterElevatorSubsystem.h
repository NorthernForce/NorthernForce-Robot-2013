/*
 * ShooterElevator.h
#include "Commands/Subsystem.h"
#include "Commands/Subsystem.h"
 *
 *  Created on: Feb 15, 2013
 *      Author: Joseph
 */


#ifndef SHOOTERELEVATOR_H_
#define SHOOTERELEVATOR_H_

#include "Commands/PIDSubsystem.h"
#include "../Library.h"
#include <Victor.h>
#include <AnalogChannel.h>

class ShooterElevatorSubsystem : public PIDSubsystem {
private:
    Victor m_shooterElevatorMotor;
    AnalogChannel m_elevationPotentiometer;
    LogFile m_elevatorLog;
    bool m_loggingEnabled;
public:
	ShooterElevatorSubsystem();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
    float GetElevationAngle();
    void SetSpeed(float speed);
    void SetPosition(float position);
    void SetPositionRelative(float deltaPos);
    void EnableLogging();
    void DisableLogging();
};

#endif /* SHOOTERELEVATOR_H_ */
