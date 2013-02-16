#include "ShooterSubsystem.h"

/**
 * @brief Initializes the drive subsystem. Catches any exception
 * that might occur in creating the jaguars. 
 */
ShooterSubsystem::ShooterSubsystem() try : 
	Subsystem("ShooterSubsystem"),
    m_shooterMotor(kShooterJaguarAddress),
    m_shooterFlicker(kShooterFlickerRelayAddress),
    m_shooterWheelLightSensor(kShooterWheelLightSensorAddress),
    m_counterLastTime(GetFPGATime())
{
	// Make sure that the shooter motor has been enabled 
	EnableMotor();
}
catch (exception e)
{
	printf("Error creating  shooter jaguar, or other shooter components.\n");
	printf(e.what());
}
    
/**
 * @brief Initializes the default command for the subsystem.
 * currently there is no default command for the shooter subsystem.
 */
void ShooterSubsystem::InitDefaultCommand() 
{
	//SetDefaultCommand();
}

/**
 * @brief Sets the speed of the shooter wheel
 * @param speed The speed to set the shooter wheel to
 */
void ShooterSubsystem::SetShooterSpeed(float speed) 
{
    m_shooterMotor.Set(speed);
}

/**
 * @brief Set the state of the solenoid which flicks the frisbees.
 * @param extend if true, the relay will be set to on, otherwise, it will be set to off. 
 */
void ShooterSubsystem::Flick(bool extend) {
    m_shooterFlicker.Set(extend ? Relay::kOn : Relay::kOff);
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

