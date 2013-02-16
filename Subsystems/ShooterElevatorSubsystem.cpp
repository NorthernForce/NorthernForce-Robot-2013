/*
 * ShooterElevator.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: Joseph
 */

#include "ShooterElevatorSubsystem.h"

ShooterElevatorSubsystem::ShooterElevatorSubsystem() :
	Subsystem("ShooterElevatorSubsystem"),
    m_shooterElevatorMotor(kShooterElevatorVictorAddress),
    m_elevationPotentiometer(kShooterElevatorPotChannel)
{
}
float ShooterElevatorSubsystem::GetElevationAngle() {
	return kElevatorDegreesPerVolt * m_elevationPotentiometer.GetVoltage();
}

void ShooterElevatorSubsystem::SetElevatorSpeed(float speed) {
	m_shooterElevatorMotor.Set(speed);
}
