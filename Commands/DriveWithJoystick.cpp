#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() 
{
	Requires(s_Drive);
}

/**
 * @brief Initializes the command.
 */
void DriveWithJoystick::Initialize() 
{
	
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void DriveWithJoystick::Execute() 
{
	s_Drive->DriveRobot(oi->GetDriverStick());
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool DriveWithJoystick::IsFinished() 
{
	return false;
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void DriveWithJoystick::End() 
{
	
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void DriveWithJoystick::Interrupted() 
{
	
}
