#include "ElevateShooter.h"

ElevateShooter::ElevateShooter(float angle) : targetAngle(angle), errorAccumulator(0.0)
{
	Requires(s_ShooterElevator);
}

/**
 * @brief Initializes the command.
 */
void ElevateShooter::Initialize()
{
	s_ShooterElevator->SetSetpoint(targetAngle);
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void ElevateShooter::Execute()
{
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool ElevateShooter::IsFinished()
{
    return s_ShooterElevator->OnTarget();
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
	
}
