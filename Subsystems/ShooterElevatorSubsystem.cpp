/*
 * ShooterElevator.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: Joseph
 */

#include "ShooterElevatorSubsystem.h"

ShooterElevatorSubsystem::ShooterElevatorSubsystem() :
	PIDSubsystem("ShooterElevatorSubsystem", kShooterElevatorP, kShooterElevatorI, kShooterElevatorD),
    m_shooterElevatorMotor(kShooterElevatorVictorAddress),
    m_elevationPotentiometer(kShooterElevatorPotChannel)
{
}

double ShooterElevatorSubsystem::ReturnPIDInput() {
	return 0.0;
}

void ShooterElevatorSubsystem::UsePIDOutput(double output) {
	m_shooterElevatorMotor.Set(output);
}

float ShooterElevatorSubsystem::GetElevationAngle() {
	return kElevatorDegreesPerVolt * m_elevationPotentiometer.GetVoltage();
}
