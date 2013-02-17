#include "ElevateShooterWithJoystick.h"

ElevateShooterWithJoystick::ElevateShooterWithJoystick()
{
	Requires(s_ShooterElevator);
}

/**
 * @brief Initializes the command.
 */
void ElevateShooterWithJoystick::Initialize() {}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void ElevateShooterWithJoystick::Execute()
{
	s_ShooterElevator->GetElevationAngle();
	s_ShooterElevator->SetSpeed(oi->GetManipulatorStick().GetY());
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool ElevateShooterWithJoystick::IsFinished()
{
    return false;
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void ElevateShooterWithJoystick::End()
{
	
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void ElevateShooterWithJoystick::Interrupted()
{
	
}
