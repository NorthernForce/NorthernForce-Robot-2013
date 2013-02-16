/*
 * ShooterElevator.h
#include "Commands/Subsystem.h"
#include "Commands/Subsystem.h"
 *
 *  Created on: Feb 15, 2013
 *      Author: Joseph
 */

#include "Commands/Subsystem.h"
#include "../Library.h"
#include <Victor.h>
#include <AnalogChannel.h>

#ifndef SHOOTERELEVATOR_H_
#define SHOOTERELEVATOR_H_

class ShooterElevatorSubsystem : public Subsystem {
private:
    Victor m_shooterElevatorMotor;
    AnalogChannel m_elevationPotentiometer;
public:
	ShooterElevatorSubsystem();
    float GetElevationAngle();
    void SetElevatorSpeed(float speed);
};

#endif /* SHOOTERELEVATOR_H_ */
