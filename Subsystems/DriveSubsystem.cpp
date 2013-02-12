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
	m_drive(m_frontLeftMotor, m_rearLeftMotor, m_frontRightMotor, m_rearRightMotor)
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
	float rate = CommandBase::s_Gyro->GetRate();
	m_drive.ArcadeDrive(stick.GetLeftStickY(), stick.GetRightStickX() + rate);
}

/**
 * @brief Drives the robot with a pair of Attack 3 joysticks.
 * @param moveStick The move Attack3Joystick to drive the robot with.
 * @param rotateStick The rotate Attack3Joystick to drive the robot with.
 */
void DriveSubsystem::DriveRobot(Attack3Joystick& moveStick, Attack3Joystick& rotateStick)
{
	//@TODO: Verify these. 
	m_drive.ArcadeDrive(moveStick, 1, rotateStick, 2);
}

/**
 * @brief Stops all motion on the robot.
 */
void DriveSubsystem::Stop()
{
	m_drive.StopMotor();
}
