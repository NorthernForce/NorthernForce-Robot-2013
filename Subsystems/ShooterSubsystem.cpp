#include "ShooterSubsystem.h"
#include "../Library.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/SpinupShooterWithJoystick.h"

/**
 * @brief Constructs the shooter subsystem.
 */
ShooterSubsystem::ShooterSubsystem() : 
    PIDSubsystem("ShooterSubsystem", kShooterP, kShooterI, kShooterD),
    m_shooterMotor(kShooterJaguarAddress),
    m_shooterWheelEncoder(kShooterWheelLightSensorAddress, 1),
    m_counterLastTime(GetFPGATime())
{
	Disable();
	GetPIDController()->SetInputRange(0.0, 4100.0);
	GetPIDController()->SetOutputRange(0.0, 1.0);
    atTarget = false;

}

/**
 * @brief Returns the PID input for the internal subsystem PID loop.
 */
double ShooterSubsystem::ReturnPIDInput() 
{
    double speed = m_shooterWheelEncoder.GetVelocity();
    SmartDashboard::PutBoolean("On Target", WithinTolerance(speed, GetSetpoint(), 50.0));
    atTarget = WithinTolerance(speed, GetSetpoint(), 50.0);
    SmartDashboard::PutNumber("Shooter Measured Speed", speed);
    return speed;
}

/**
 * @brief Uses the output of the internal PID loop.
 * @param output The output of the PID loop. 
 */
void ShooterSubsystem::UsePIDOutput(double output) 
{
    m_shooterMotor.Set(-output);
}

/**
 * @brief Initializes the default command for the subsystem.
 */
void ShooterSubsystem::InitDefaultCommand() 
{

}

/**
 * @brief Resets the counter for determining the speed of the shooter wheel.
 */
void ShooterSubsystem::ResetEncoder() 
{
	m_shooterWheelEncoder.Reset();
}

/**
 * @brief Sets the speed of the wheel. Works with either PID 
 * or voltage values.
 * @param speed The speed to set the wheel to, either in percentage or RPM. 
 */
void ShooterSubsystem::SetSpeed(float speed) 
{
	if (SHOOTER_PID_ENABLE)
	{
		Enable();
		SetSetpoint((double)speed);
		SmartDashboard::PutNumber("Shooter Setpoint", GetSetpoint());
	}
	else if (!SHOOTER_PID_ENABLE)
	{
		Disable();
		m_shooterMotor.Set(speed);
	}
}

/**
 * @brief Stops the shooter motor.
 * NOTE: This will disable the motor, which will not
 * be re-enabled until after the robot has been restarted,
 * or the ShooterSubsystem::EnableMotor method is called
 */
void ShooterSubsystem::Stop()
{
	SetSpeed(0.0);
}

/**
 * @brief Re-enables the shooter motor.
 */
void ShooterSubsystem::EnableMotor() 
{
	m_shooterWheelEncoder.Reset();
	if (SHOOTER_PID_ENABLE)
	{
		m_shooterMotor.EnableControl(0.0);
		Enable();
	}
	else if (!SHOOTER_PID_ENABLE)
	{
		m_shooterMotor.EnableControl(0.0);
	}
}

