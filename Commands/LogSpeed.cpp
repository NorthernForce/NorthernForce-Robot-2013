#include "LogSpeed.h"
#include "../Library.h"

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
    if(c>10) {
        c = 0;
        float speed = s_Shooter->GetSpeed();
        s_Shooter->atTarget = (speed > 3000.0);
        SmartDashboard::PutBoolean("On Target", s_Shooter->atTarget);
        SmartDashboard::PutNumber("Shooter Measured Speed", speed);
        SmartDashboard::PutNumber("Shooter Setpoint", 3000.0);
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
