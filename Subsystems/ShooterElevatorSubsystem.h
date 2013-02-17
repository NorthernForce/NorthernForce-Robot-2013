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
public:
	ShooterElevatorSubsystem();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
    float GetElevationAngle();
};

#endif /* SHOOTERELEVATOR_H_ */
