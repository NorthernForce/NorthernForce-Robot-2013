#include "LogPOT.h"

LogPOT::LogPOT() 
{
    Requires(s_ShooterElevator);
}

/**
 * @brief Initializes the command.
 */
void LogPOT::Initialize() 
{
    s_ShooterElevator->EnableLogging();
	printf("POT Voltage: %f\n", s_ShooterElevator->GetElevationAngle());
    s_ShooterElevator->DisableLogging();
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void LogPOT::Execute() 
{
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool LogPOT::IsFinished() 
{
    return true;
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void LogPOT::End() 
{
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void LogPOT::Interrupted() 
{
	
}
