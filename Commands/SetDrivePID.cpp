#include "SetDrivePID.h"

SetDrivePID::SetDrivePID()
{

}

/**
 * @brief Initializes the command.
 */
void SetDrivePID::Initialize() 
{
	s_Drive->ChangeDrivePID(DriverStation::GetInstance()->GetAnalogIn(1), 
		DriverStation::GetInstance()->GetAnalogIn(2), DriverStation::GetInstance()->GetAnalogIn(3));
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void SetDrivePID::Execute() 
{

}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool SetDrivePID::IsFinished() 
{
	return true;
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void SetDrivePID::End() 
{
	
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void SetDrivePID::Interrupted() 
{
	
}
