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
    float angle = kElevatorDegreesPerVolt * (kElevatorZero - voltage);
	if(m_loggingEnabled) {
		char _tmp[35];
		sprintf(_tmp, "Voltage: %5.3f, Angle: %5.3f deg", voltage, angle);
		printf("Voltage: %5.3f, Angle: %5.3f deg", voltage, angle);
		m_elevatorLog.Write(_tmp);
	}	
	return angle;
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

void ShooterElevatorSubsystem::EnableLogging() {
    m_loggingEnabled = true;
}

void ShooterElevatorSubsystem::DisableLogging() {
    m_loggingEnabled = false;
}
