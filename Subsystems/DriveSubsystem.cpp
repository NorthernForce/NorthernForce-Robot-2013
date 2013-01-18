#include "DriveSubsystem.h"

/**
 * @brief Initializes the drive subsystem. Catches any exception
 * that might occur in creating the jaguars. 
 */
DriveSubsystem::DriveSubsystem() try : 
	Subsystem("DriveSubsystem"),
	m_frontLeftMotor((printf("Initializing front left jaguar. \n"), kFrontLeftJaguarAddress)),
	m_frontRightMotor((printf("Initializing front right jaguar. \n"), kFrontRightJaguarAddress)),
	m_rearLeftMotor((printf("Initializing rear left jaguar. \n"), kRearLeftJaguarAddress)),
	m_rearRightMotor((printf("Initializing rear right jaguar. \n"), kRearRightJaguarAddress)),
	m_drive(m_frontLeftMotor, m_rearLeftMotor, m_frontRightMotor, m_rearRightMotor)
{
	//@TODO: Set up drive class. 
}
catch (exception e)
{
	printf("Error creating jaguars.");
	printf(e.what());
}
    
/**
 * @brief Initializes the default command for the subsystem.
 */
void DriveSubsystem::InitDefaultCommand() 
{
	
}

/**
 * @brief Drives the robot with an XBox Joystick.
 * @param stick The FRCXboxJoystick to drive the robot with.
 */
void DriveSubsystem::DriveWithJoystick(FRCXboxJoystick& stick)
{
	//@TODO: Verify these axis values. 
	m_drive.ArcadeDrive(stick.GetRightStickX(), stick.GetLeftStickY());
}

/**
 * @brief Drives the robot with a pair of Attack 3 joysticks.
 * @param moveStick The move Attack3Joystick to drive the robot with.
 * @param rotateStick The rotate Attack3Joystick to drive the robot with.
 */
void DriveSubsystem::DriveWithJoystick(Attack3Joystick& moveStick, Attack3Joystick& rotateStick)
{
	//@TODO: Verify these. 
	m_drive.ArcadeDrive(moveStick, 1, rotateStick, 2);
}
