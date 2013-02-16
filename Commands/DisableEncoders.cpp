#include "DisableEncoders.h"

DisableEncoders::DisableEncoders() 
{

}

/**
 * @brief Initializes the command.
 */
void DisableEncoders::Initialize() 
{
	s_Drive->DisableEncoders();
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void DisableEncoders::Execute() 
{

}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool DisableEncoders::IsFinished() 
{
	return !s_Drive->EncodersEnabled();
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void DisableEncoders::End() 
{
	
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void DisableEncoders::Interrupted() 
{
	
}
