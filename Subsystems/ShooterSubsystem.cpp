#include "ShooterSubsystem.h"
#include "../Library.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/SpinupShooterWithJoystick.h"

ShooterSubsystem::ShooterSubsystem() : 
    PIDSubsystem("ShooterSubsystem", kShooterP, kShooterI, kShooterD),
    m_shooterMotor(kShooterJaguarAddress),
    m_shooterFlicker(kShooterFlickerRelayAddress, Relay::kBothDirections),
    m_shooterWheelLightSensor(kShooterWheelLightSensorAddress),
    m_counterLastTime(GetFPGATime())
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	Disable();
    m_shooterMotor.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
    m_shooterMotor.ChangeControlMode(CANJaguar::kPercentVbus);
}

double ShooterSubsystem::ReturnPIDInput() 
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
    float speed = GetAvgSpeed();
    ResetCounter();
    return speed;
}

void ShooterSubsystem::UsePIDOutput(double output) 
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
    m_shooterMotor.Set(output);
}

void ShooterSubsystem::InitDefaultCommand() 
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
//	SetDefaultCommand(new SpinupShooterWithJoystick());
}

/**
 * @brief Set the state of the solenoid which flicks the frisbees.
 * @param dir The direction to set the relay to. 
 */
void ShooterSubsystem::Flick(Relay::Value dir) 
{
    m_shooterFlicker.Set(dir);
}

/**
 * @brief Resets the counter for determining the speed of the shooter wheel.
 */
void ShooterSubsystem::ResetCounter() 
{
	m_counterLastTime = GetFPGATime();
	m_shooterWheelLightSensor.Reset();
}

void ShooterSubsystem::SetSpeed(float speed) 
{
	Disable();
	m_shooterMotor.Set(speed);
}

/**
 * @return the average speed since the last counter reset.
 */
float ShooterSubsystem::GetAvgSpeed() 
{
	return 2 * ((float)m_shooterWheelLightSensor.Get())/(GetFPGATime() - m_counterLastTime);
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

void ShooterSubsystem::EnableMotor() 
{
	m_shooterMotor.EnableControl(0.0);
}

