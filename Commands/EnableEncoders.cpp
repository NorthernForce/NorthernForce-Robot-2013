#include "EnableEncoders.h"

EnableEncoders::EnableEncoders() 
{

}

/**
 * @brief Initializes the command.
 */
void EnableEncoders::Initialize() 
{
	
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void EnableEncoders::Execute() 
{
	s_Drive->EnableEncoders();
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool EnableEncoders::IsFinished() 
{
	return s_Drive->EncodersEnabled();
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void EnableEncoders::End() 
{
	
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void EnableEncoders::Interrupted() 
{
	
}
