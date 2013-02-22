#include "TurnToAngle.h"

TurnToAngle::TurnToAngle(float angle) :
	m_targetAngle(angle) 
{
	Requires(s_Drive);
}

/**
 * @brief Initializes the command.
 */
void TurnToAngle::Initialize() 
{
	printf("Initializing...\n");
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void TurnToAngle::Execute() 
{
	s_Drive->DriveRobot(0.0, 0.2 * (m_targetAngle - s_Gyro->GetAngle()));
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool TurnToAngle::IsFinished() 
{
	return WithinTolerance(s_Gyro->GetAngle(), m_targetAngle, 0.2);
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void TurnToAngle::End() 
{
	s_Drive->DriveRobot(0.0, 0.0);
	printf("At target angle.");
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void TurnToAngle::Interrupted() 
{
	End();
}
