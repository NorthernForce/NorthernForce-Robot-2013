#include "ShooterElevatorSubsystem.h"
#include "../Commands/ElevateShooterWithJoystick.h"

ShooterElevatorSubsystem::ShooterElevatorSubsystem() :
	PIDSubsystem("ShooterElevatorSubsystem", kShooterElevatorP, kShooterElevatorI, kShooterElevatorD),
    m_shooterElevatorMotor(kShooterElevatorVictorAddress),
    m_elevationPotentiometer(kShooterElevatorPotChannel),
    m_elevatorLog("POTLog.txt"),
    m_loggingEnabled(false)
{
//	this->SetSetpoint(kPyramidBackAngle);
//	Enable();
	Disable();
}

double ShooterElevatorSubsystem::ReturnPIDInput() 
{
	return this->GetElevationAngle();
}

void ShooterElevatorSubsystem::UsePIDOutput(double output) 
{
	m_shooterElevatorMotor.Set(output);
}

void ShooterElevatorSubsystem::InitDefaultCommand() 
{
	//SetDefaultCommand(new ElevateShooterWithJoystick());
}

float ShooterElevatorSubsystem::GetElevationAngle() 
{
	float voltage = m_elevationPotentiometer.GetVoltage();
    float angle = kElevatorDegreesPerVolt * (kElevatorZero - voltage);
    
	if(m_loggingEnabled) {
		char _tmp[55];
		sprintf(_tmp, "Voltage: %5.3f, Angle: %5.3f deg, Shooter Speed %5.3f", 
				voltage, angle, CommandBase::oi->GetManipulatorStick().GetPOT());
		printf("Voltage: %5.3f, Angle: %5.3f deg, Shooter Speed %5.3f\n", 
				voltage, angle, CommandBase::oi->GetManipulatorStick().GetPOT());
		m_elevatorLog.Write(_tmp);
	}
	
	return angle;
}

void ShooterElevatorSubsystem::SetPosition(float position) 
{
	//@TODO: Test this. 
    if(position > kElevatorMaxAngle) { SetSetpoint(kElevatorMaxAngle); }
    else if(position < kElevatorMinAngle) { SetSetpoint(kElevatorMinAngle); }
	else { SetSetpoint(position); }

	Enable();

	// if(position > kElevatorMaxAngle) position = kElevatorMaxAngle;
	// if(position < kElevatorMinAngle) position = kElevatorMinAngle;
	// SetSetpoint(position);
	// Enable();
}

void ShooterElevatorSubsystem::SetPositionRelative(float deltaPos) 
{
	Enable();
    if((deltaPos + GetSetpoint()) > kElevatorMaxAngle) { SetSetpoint(kElevatorMaxAngle); }
    else if((deltaPos + GetSetpoint()) < kElevatorMinAngle) { SetSetpoint(kElevatorMinAngle); }
	else { SetSetpointRelative(deltaPos); }
}

void ShooterElevatorSubsystem::SetSpeed(float speed) 
{
	Disable();
    if((GetElevationAngle() > kElevatorMaxAngle) && (speed > 0.0)) return;
    if((GetElevationAngle() < kElevatorMinAngle) && (speed < 0.0)) return;
	m_shooterElevatorMotor.Set(speed);
}

void ShooterElevatorSubsystem::EnableLogging() 
{
    m_loggingEnabled = true;
}

void ShooterElevatorSubsystem::DisableLogging() 
{
    m_loggingEnabled = false;
}
