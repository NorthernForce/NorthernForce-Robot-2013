#include "ElevateShooter.h"

ElevateShooter::ElevateShooter(float angle) : targetAngle(angle)
{
	Requires(s_ShooterElevator);
}

/**
 * @brief Initializes the command.
 */
void ElevateShooter::Initialize()
{

}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void ElevateShooter::Execute()
{
	s_ShooterElevator->SetPosition(targetAngle);
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool ElevateShooter::IsFinished()
{
    return TimeSinceInitialized() > 1.0;
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void ElevateShooter::End()
{
	
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void ElevateShooter::Interrupted()
{
	End();
}
