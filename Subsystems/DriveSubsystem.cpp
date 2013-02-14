#include "DriveSubsystem.h"
#include "../Commands/DriveWithJoystick.h"
/**
 * @brief Initializes the drive subsystem. Catches any exception
 * that might occur in creating the jaguars. 
 */
DriveSubsystem::DriveSubsystem() try : 
	Subsystem("DriveSubsystem"),
	m_frontLeftMotor((printf("Initializing front left jaguar. \n"), kFrontLeftJaguarAddress), 
			kDriveRamp, kDriveVelocityLimit, kDriveTolerance, kDriveThereTolerance),
	m_frontRightMotor((printf("Initializing front right jaguar. \n"), kFrontRightJaguarAddress), 
			kDriveRamp, kDriveVelocityLimit, kDriveTolerance, kDriveThereTolerance),
	m_rearLeftMotor((printf("Initializing rear left jaguar. \n"), kRearLeftJaguarAddress), 
			kDriveRamp, kDriveVelocityLimit, kDriveTolerance, kDriveThereTolerance),
	m_rearRightMotor((printf("Initializing rear right jaguar. \n"), kRearRightJaguarAddress), 
			kDriveRamp, kDriveVelocityLimit, kDriveTolerance, kDriveThereTolerance),
	m_drive(m_frontLeftMotor, m_rearLeftMotor, m_frontRightMotor, m_rearRightMotor),
	m_driveErrAccumulator(0.0),
    m_DriveLog("DriveLog.csv"),
    m_loggingEnabled(false),
    m_gyroEnabled(true)
{
	m_frontLeftMotor.ConfigNeutralMode(RampedCANJaguar::kNeutralMode_Brake);
	m_frontRightMotor.ConfigNeutralMode(RampedCANJaguar::kNeutralMode_Brake);
	m_rearLeftMotor.ConfigNeutralMode(RampedCANJaguar::kNeutralMode_Brake);
	m_rearRightMotor.ConfigNeutralMode(RampedCANJaguar::kNeutralMode_Brake);
}
catch (exception e)
{
	printf("Error creating drive motor jaguars.");
	printf(e.what());
}
    
/**
 * @brief Initializes the default command for the subsystem.
 */
void DriveSubsystem::InitDefaultCommand() 
{
	SetDefaultCommand(new DriveWithJoystick());
}

/**
 * @brief Drives the robot with an XBox Joystick.
 * @param stick The FRCXboxJoystick to drive the robot with.
 */
void DriveSubsystem::DriveRobot(FRCXboxJoystick& stick)
{
	if (m_gyroEnabled)
	{
		float gyroRate = CommandBase::s_Gyro->GetRate();
	    float spin = stick.GetRightStickX();
	    float error = spin - gyroRate;
	    m_driveErrAccumulator = m_driveErrAccumulator + error;
	    
	    if (m_loggingEnabled)
	    {
		    char _tmp[200];
		    sprintf(_tmp, "%f,%f,%f,%f",spin,gyroRate,error,m_driveErrAccumulator);
		    m_DriveLog.Write(_tmp);
		}
		
		m_drive.ArcadeDrive(stick.GetLeftStickY(), kDriveSpinP * error + kDriveSpinI * m_driveErrAccumulator);
	}
	else
	{
		m_drive.ArcadeDrive(stick.GetLeftStickY(), stick.GetRightStickY());
	}
}

/**
 * @brief Drives the robot with a pair of Attack 3 joysticks.
 * @param moveStick The move Attack3Joystick to drive the robot with.
 * @param rotateStick The rotate Attack3Joystick to drive the robot with.
 */
void DriveSubsystem::DriveRobot(Attack3Joystick& moveStick, Attack3Joystick& rotateStick)
{
	m_drive.ArcadeDrive(moveStick, 1, rotateStick, 2);
}

/**
 * @brief Drives the robot given a move value and a rotate value.
 * @param moveValue The speed to move forwards and backwards.
 * @param rotateValue The speed to rotate the robot.
 */
void DriveSubsystem::DriveRobot(float moveValue, float rotateValue)
{
	m_drive.ArcadeDrive(moveValue, rotateValue, true);
}

/**
 * @brief Stops all motion on the robot.
 */
void DriveSubsystem::Stop()
{
	m_drive.StopMotor();
}

/**
 * @brief Disables the gyro correction in drive.
 */
void DriveSubsystem::DisableGyro()
{
	CommandBase::s_Log->LogMessage("Disabling gyro-aided drive...");
	m_gyroEnabled = false;
}

/**
 * @brief Enables the gyro correction in drive.
 */
void DriveSubsystem::EnableGyro()
{
	CommandBase::s_Log->LogMessage("Enabling gyro-aided drive...");
	m_gyroEnabled = true;
}

/**
 * @brief Enables logging of drive information.
 */
void DriveSubsystem::EnableLogging()
{
	CommandBase::s_Log->LogMessage("Enabling drive logging...");
	m_loggingEnabled = true;
}

/**
 * @brief Disables logging of drive information.
 */
void DriveSubsystem::DisableLogging()
{
	CommandBase::s_Log->LogMessage("Disabling drive logging...");
	m_loggingEnabled = false;
}


double DriveSubsystem::GetAvgDistance()
{
	return( ( m_frontLeftMotor.GetPosition() + m_frontRightMotor.GetPosition() ) / 2 );	

}
