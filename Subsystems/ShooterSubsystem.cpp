#include "ShooterSubsystem.h"
#include "../Library.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/SpinupShooterWithJoystick.h"

ShooterSubsystem::ShooterSubsystem() : 
    PIDSubsystem("ShooterSubsystem", kShooterP, kShooterI, kShooterD),
    m_shooterMotor(kShooterJaguarAddress),
    m_shooterWheelEncoder(kShooterWheelLightSensorAddress, 1),
    m_counterLastTime(GetFPGATime())
{
	Disable();
	GetPIDController()->SetInputRange(0.0, 4100.0);
	GetPIDController()->SetOutputRange(0.0, 1.0);
	GetPIDController()->SetTolerance(0.035);
    atTarget = false;

}

double ShooterSubsystem::ReturnPIDInput() 
{
    double speed = m_shooterWheelEncoder.GetVelocity();
    SmartDashboard::PutBoolean("On Target", GetPIDController()->OnTarget());
    SmartDashboard::PutNumber("Shooter Measured Speed", speed);
    return speed;
}

void ShooterSubsystem::UsePIDOutput(double output) 
{
    m_shooterMotor.PIDWrite((float)output);
}

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
//    m_shooterMotor.DisableControl();
//    Disable();
}

void ShooterSubsystem::EnableMotor() 
{
//	m_shooterMotor.EnableControl(0.0);
}

