#include "ShooterSubsystem.h"
#include "../Library.h"
#include "SmartDashboard/SmartDashboard.h"

ShooterSubsystem::ShooterSubsystem() : 
    PIDSubsystem("ShooterSubsystem", Kp, Ki, Kd),
    m_shooterMotor(kShooterJaguarAddress),
    m_shooterFlicker(kShooterFlickerRelayAddress),
    m_shooterWheelLightSensor(kShooterWheelLightSensorAddress),
    m_counterLastTime(GetFPGATime())
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double ShooterSubsystem::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
    float speed = GetAvgSpeed();
    ResetCounter();
    return speed;
}

void ShooterSubsystem::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
    m_shooterMotor.Set(output);
}

void ShooterSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

/**
 * @brief Set the state of the solenoid which flicks the frisbees.
 * @param extend if true, the relay will be set to on, otherwise, it will be set to off. 
 */
void ShooterSubsystem::Flick(bool on) {
    m_shooterFlicker.Set(on ? Relay::kOn : Relay::kOff);
}

/**
 * @brief Resets the counter for determining the speed of the shooter wheel.
 */
void ShooterSubsystem::ResetCounter() {
	m_counterLastTime = GetFPGATime();
	m_shooterWheelLightSensor.Reset();
}

/**
 * @return the average speed since the last counter reset.
 */
float ShooterSubsystem::GetAvgSpeed() {
	return (float)m_shooterWheelLightSensor.Get()/(GetFPGATime() - m_counterLastTime);
}

/**
 * @brief Stops the shooter motor.
 * NOTE: This will disable the motor, which will not
 * be re-enabled until after the robot has been restarted,
 * or the ShooterSubsystem::EnableMotor method is called
 */
void ShooterSubsystem::Stop()
{
    m_shooterMotor.DisableControl();
}

void ShooterSubsystem::EnableMotor() {
	m_shooterMotor.EnableControl(0.0);
}

