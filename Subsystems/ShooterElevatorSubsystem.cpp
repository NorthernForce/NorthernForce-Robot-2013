/*
 * ShooterElevator.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: Joseph
 */

#include "ShooterElevatorSubsystem.h"
#include "../Commands/ElevateShooterWithJoystick.h"

ShooterElevatorSubsystem::ShooterElevatorSubsystem() :
	PIDSubsystem("ShooterElevatorSubsystem", kShooterElevatorP, kShooterElevatorI, kShooterElevatorD),
    m_shooterElevatorMotor(kShooterElevatorVictorAddress),
    m_elevationPotentiometer(kShooterElevatorPotChannel),
    m_elevatorLog("POTLog.txt"),
    m_loggingEnabled(false)
{
	Disable();
}

double ShooterElevatorSubsystem::ReturnPIDInput() {
	return GetElevationAngle();
}

void ShooterElevatorSubsystem::UsePIDOutput(double output) {
	m_shooterElevatorMotor.Set(output);
}

void ShooterElevatorSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new ElevateShooterWithJoystick());
}

float ShooterElevatorSubsystem::GetElevationAngle() {
	float voltage = m_elevationPotentiometer.GetVoltage();
	if(m_loggingEnabled) {
		char _tmp[10];
		sprintf(_tmp, "POT Voltage: %5.3f", voltage);
		m_elevatorLog.Write(_tmp);
	}	
	return kElevatorDegreesPerVolt * voltage;
}

void ShooterElevatorSubsystem::SetPosition(float position) {
	Enable();
	SetSetpoint(position);
}

void ShooterElevatorSubsystem::SetPositionRelative(float deltaPos) {
	Enable();
	SetSetpointRelative(deltaPos);
}

void ShooterElevatorSubsystem::SetSpeed(float speed) {
	Disable();
	m_shooterElevatorMotor.Set(speed);
}
