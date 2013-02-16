#include "DriveSubsystem.h"
#include "../Commands/DriveWithJoystick.h"

/**
 * @brief Initializes the drive subsystem. Catches any exception
 * that might occur in creating the jaguars. 
 */
DriveSubsystem::DriveSubsystem() try : 
	Subsystem("DriveSubsystem"),
	m_frontLeftMotor((CommandBase::s_Log->LogMessage("Initializing front left jaguar. \n", kLogPriorityDebug), 
		kFrontLeftJaguarAddress), kDriveRamp, kDriveVelocityLimit, kDriveTolerance, kDriveThereTolerance),
	m_frontRightMotor((CommandBase::s_Log->LogMessage("Initializing front right jaguar. \n", kLogPriorityDebug), 
		kFrontRightJaguarAddress), kDriveRamp, kDriveVelocityLimit, kDriveTolerance, kDriveThereTolerance),
	m_rearLeftMotor((CommandBase::s_Log->LogMessage("Initializing rear left jaguar. \n", kLogPriorityDebug), 
		kRearLeftJaguarAddress), kDriveRamp, kDriveVelocityLimit, kDriveTolerance, kDriveThereTolerance),
	m_rearRightMotor((CommandBase::s_Log->LogMessage("Initializing rear right jaguar. \n", kLogPriorityDebug), 
		kRearRightJaguarAddress), kDriveRamp, kDriveVelocityLimit, kDriveTolerance, kDriveThereTolerance),
	m_drive(m_frontLeftMotor, m_rearLeftMotor, m_frontRightMotor, m_rearRightMotor),
	m_driveErrAccumulator(0.0),
    m_DriveLog("DriveLog.csv"),
    m_loggingEnabled(false),
    m_gyroEnabled(false),
    m_encodersEnabled(true)
{
	(m_encodersEnabled) ? this->EnableEncoders() : this->DisableEncoders();
}
catch (exception e)
{
	CommandBase::s_Log->LogMessage("Error creating drive motor jaguars.", kLogPriorityError);
	CommandBase::s_Log->LogMessage(e.what(), kLogPriorityError);
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
	this->DriveRobot(stick.GetLeftStickY(), stick.GetTrigger());
}

/**
 * @brief Drives the robot with a pair of Attack 3 joysticks.
 * @param moveStick The move Attack3Joystick to drive the robot with.
 * @param rotateStick The rotate Attack3Joystick to drive the robot with.
 */
void DriveSubsystem::DriveRobot(Attack3Joystick& moveStick, Attack3Joystick& rotateStick)
{
	this->DriveRobot(moveStick.GetY(), moveStick.GetX());
}
 
/**
 * @brief Drives the robot given a move value and a rotate value.
 * @param moveValue The speed to move forwards and backwards.
 * @param rotateValue The speed to rotate the robot.
 */
void DriveSubsystem::DriveRobot(float moveValue, float rotateValue)
{
	if (m_gyroEnabled)
	{
		float gyroRate = CommandBase::s_Gyro->GetRate();
	    float error = rotateValue - gyroRate;
	    m_driveErrAccumulator += error;
	    
	    if (m_loggingEnabled)
	    {
		    char _tmp[40];
		    sprintf(_tmp, "%5.3f,%5.3f,%5.3f,%5.3f", rotateValue,gyroRate,error,m_driveErrAccumulator);
		    m_DriveLog.Write(_tmp);
		}
		
		m_drive.ArcadeDrive(moveValue, kDriveSpinP * error + kDriveSpinI * m_driveErrAccumulator, true);
	}
	else
	{
		m_drive.ArcadeDrive(moveValue, rotateValue, true);
	}
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
	CommandBase::s_Log->LogMessage("Disabling gyro-aided drive...", kLogPriorityDebug);
	m_gyroEnabled = false;
}

/**
 * @brief Enables the gyro correction in drive.
 */
void DriveSubsystem::EnableGyro()
{
	CommandBase::s_Log->LogMessage("Enabling gyro-aided drive...", kLogPriorityDebug);
	m_gyroEnabled = true;
}

/**
 * @brief Enables logging of drive information.
 */
void DriveSubsystem::EnableLogging()
{
	CommandBase::s_Log->LogMessage("Enabling drive logging...", kLogPriorityDebug);
	m_loggingEnabled = true;
}

/**
 * @brief Disables logging of drive information.
 */
void DriveSubsystem::DisableLogging()
{
	CommandBase::s_Log->LogMessage("Disabling drive logging...", kLogPriorityDebug);
	m_loggingEnabled = false;
}


double DriveSubsystem::GetAvgDistance()
{
	return( ( m_frontLeftMotor.GetPosition() + m_frontRightMotor.GetPosition() ) / 2 );	

}

/**
 * @brief Enables driving with encoders. Also used for initializing 
 * encoder-driven jaguars.
 */
void DriveSubsystem::EnableEncoders()
{
	CommandBase::s_Log->LogMessage("Enabling encoders...", kLogPriorityDebug);

	m_frontLeftMotor.DisableControl();
	m_frontRightMotor.DisableControl();
	m_rearLeftMotor.DisableControl();
	m_rearRightMotor.DisableControl();

	m_frontLeftMotor.ChangeControlMode(CANJaguar::kSpeed);
	m_frontRightMotor.ChangeControlMode(CANJaguar::kSpeed);
	m_rearLeftMotor.ChangeControlMode(CANJaguar::kSpeed);
	m_rearRightMotor.ChangeControlMode(CANJaguar::kSpeed);

	m_frontLeftMotor.SetPID(kDriveP, kDriveI, kDriveD);
	m_frontRightMotor.SetPID(kDriveP, kDriveI, kDriveD);
	m_rearLeftMotor.SetPID(kDriveP, kDriveI, kDriveD);
	m_rearRightMotor.SetPID(kDriveP, kDriveI, kDriveD);
	m_frontLeftMotor.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_frontRightMotor.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_rearLeftMotor.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_rearRightMotor.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);

	m_frontLeftMotor.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
	m_frontRightMotor.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
	m_rearLeftMotor.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
	m_rearRightMotor.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);

	m_frontLeftMotor.ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	m_frontRightMotor.ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	m_rearLeftMotor.ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	m_rearRightMotor.ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	m_encodersEnabled = true;

	m_frontLeftMotor.EnableControl();
	m_frontRightMotor.EnableControl();
	m_rearLeftMotor.EnableControl();
	m_rearRightMotor.EnableControl();

	CommandBase::s_Log->LogMessage("Encoders enabled!", kLogPriorityDebug);
}

/**
 * @brief Disables driving with encoders. Also used for initializing
 * non encoder-driven jaguars.
 */
void DriveSubsystem::DisableEncoders()
{
	CommandBase::s_Log->LogMessage("Disabling encoders...", kLogPriorityDebug);

	m_frontLeftMotor.DisableControl();
	m_frontRightMotor.DisableControl();
	m_rearLeftMotor.DisableControl();
	m_rearRightMotor.DisableControl();

	m_frontLeftMotor.ChangeControlMode(CANJaguar::kPercentVbus);
	m_frontRightMotor.ChangeControlMode(CANJaguar::kPercentVbus);
	m_rearLeftMotor.ChangeControlMode(CANJaguar::kPercentVbus);
	m_rearRightMotor.ChangeControlMode(CANJaguar::kPercentVbus);
	m_encodersEnabled = false;

	m_frontLeftMotor.EnableControl();
	m_frontRightMotor.EnableControl();
	m_rearLeftMotor.EnableControl();
	m_rearRightMotor.EnableControl();

	CommandBase::s_Log->LogMessage("Encoders disabled!", kLogPriorityDebug);
}

/**
 * @brief Changes the PID values on the drive encoders.
 * @param p The P value to set.
 * @param i The I value to set.
 * @param d The D value to set.
 */
void DriveSubsystem::ChangeDrivePID(float p, float i, float d)
{
	CommandBase::s_Log->LogMessage("Changing drive PID values...", kLogPriorityDebug);

	m_frontLeftMotor.DisableControl();
	m_frontRightMotor.DisableControl();
	m_rearLeftMotor.DisableControl();
	m_rearRightMotor.DisableControl();

	m_frontLeftMotor.SetPID(p, i, d);
	m_frontRightMotor.SetPID(p, i, d);
	m_rearLeftMotor.SetPID(p, i, d);
	m_rearRightMotor.SetPID(p, i, d);
	
	m_frontLeftMotor.EnableControl();
	m_frontRightMotor.EnableControl();
	m_rearLeftMotor.EnableControl();
	m_rearRightMotor.EnableControl();

	char _tmp[100];
	sprintf(_tmp, "Drive PID values changed to %f %f %f.", p, i, d);
	CommandBase::s_Log->LogMessage(_tmp, kLogPriorityDebug);
}
