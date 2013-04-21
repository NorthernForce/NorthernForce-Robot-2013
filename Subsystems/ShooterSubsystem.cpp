#include "ShooterSubsystem.h"
#include "../Library.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/SpinupShooterWithJoystick.h"

ShooterSubsystem::ShooterSubsystem() : 
    PIDSubsystem("ShooterSubsystem", kShooterP, kShooterI, kShooterD),
    m_shooterMotor(kShooterJaguarAddress),
    m_shooterWheelLightSensor(kShooterWheelLightSensorAddress),
    m_counterLastTime(GetFPGATime())
{
	Disable();
	GetPIDController()->SetInputRange(0.0, 4100.0);
	GetPIDController()->SetOutputRange(0.0, 1.0);
//    m_shooterMotor.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
//    m_shooterMotor.ChangeControlMode(CANJaguar::kPercentVbus);
    m_shooterWheelLightSensor.Start();

}

double ShooterSubsystem::ReturnPIDInput() 
{
    float speed = this->GetAvgSpeed();
    this->ResetCounter();
    SmartDashboard::PutBoolean("On Target", WithinTolerance((double)speed, GetSetpoint(), 100.0));
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
void ShooterSubsystem::ResetCounter() 
{
	m_counterLastTime = GetFPGATime();
	m_shooterWheelLightSensor.Reset();
}

//void ShooterSubsystem::SetSpeed(float speed) 
//{
//	Enable();
//	SetSetpoint((double)speed);
//	SmartDashboard::PutNumber("Shooter Setpoint", GetSetpoint());
//}

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
    UINT32 now = GetFPGATime();
    float rotations = m_shooterWheelLightSensor.Get();
    float speed = rotations/(now - m_counterLastTime);
    m_counterLastTime = now;
	return speed * 1000000.0 * 60;
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

