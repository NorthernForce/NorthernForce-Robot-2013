#include "EnableGyro.h"

EnableGyro::EnableGyro() 
{

}

/**
 * @brief Initializes the command.
 */
void EnableGyro::Initialize() 
{
	s_Drive->EnableGyro();
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void EnableGyro::Execute() 
{

}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool EnableGyro::IsFinished() 
{
	return s_Drive->GyroEnabled();
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void EnableGyro::End() 
{
	
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void EnableGyro::Interrupted() 
{
	
}
