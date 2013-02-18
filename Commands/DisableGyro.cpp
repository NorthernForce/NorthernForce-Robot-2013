#include "DisableGyro.h"

DisableGyro::DisableGyro() 
{

}

/**
 * @brief Initializes the command.
 */
void DisableGyro::Initialize() 
{
	s_Drive->DisableGyro();
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void DisableGyro::Execute() 
{

}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool DisableGyro::IsFinished() 
{
	return !s_Drive->GyroEnabled();
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void DisableGyro::End() 
{
	
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void DisableGyro::Interrupted() 
{
	
}

