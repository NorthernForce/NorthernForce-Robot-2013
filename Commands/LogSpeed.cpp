#include "LogSpeed.h"

LogSpeed::LogSpeed() 
{
    //Requires(s_ShooterElevator);
}

/**
 * @brief Initializes the command.
 */
void LogSpeed::Initialize() 
{
    //s_ShooterElevator->EnableLogging();
	//s_ShooterElevator->GetElevationAngle();
    //s_ShooterElevator->DisableLogging();
    c = 0;
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void LogSpeed::Execute() 
{
    c++;
    if(c>100) {
        c = 0;
        printf("%f\n", s_Shooter->GetAvgSpeed());
        s_Shooter->ResetCounter();
    }
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool LogSpeed::IsFinished() 
{
    return false;
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void LogSpeed::End() 
{
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void LogSpeed::Interrupted() 
{
	
}
