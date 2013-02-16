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
	
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void ElevateShooter::Execute()
{
	float shooterElevator_p = 1.0;
	float shooterElevator_i = 0.0;
	float error = targetAngle - s_ShooterElevator->GetElevationAngle();
	errorAccumulator += error;

	s_ShooterElevator->SetElevatorSpeed(shooterElevator_p * error + shooterElevator_i * errorAccumulator);
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool ElevateShooter::IsFinished()
{
	return false;
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
