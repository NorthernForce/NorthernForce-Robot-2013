#include "TurnToRelativeAngle.h"

TurnToRelativeAngle::TurnToRelativeAngle(float angle) :
	m_targetAngle(angle)
{
	Requires(s_Drive);
}

/**
 * @brief Initializes the command.
 */
void TurnToRelativeAngle::Initialize() 
{
//	printf("Initializing...\n");
	s_Gyro->Reset();
//	printf("Turning to %f.\n",m_targetAngle);
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void TurnToRelativeAngle::Execute() 
{
	 s_Drive->DriveRobot(0.0, -0.057 * (m_targetAngle - s_Gyro->GetAngle()));
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool TurnToRelativeAngle::IsFinished() 
{
	return WithinTolerance<float>(s_Gyro->GetAngle(), m_targetAngle, 2);
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void TurnToRelativeAngle::End() 
{
	s_Drive->DriveRobot(0.0, 0.0);
	printf("At target angle.\n");
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void TurnToRelativeAngle::Interrupted() 
{
	printf("Interrupted!\n");
	End();
}
