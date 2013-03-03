#include "TurnToAngleCamera.h"

TurnToAngleCamera::TurnToAngleCamera() :
    m_integral(0.0)
{
	Requires(s_Drive);
}

/**
 * @brief Initializes the command.
 */
void TurnToAngleCamera::Initialize() 
{
//	printf("Initializing...\n");
  	m_targetAngle = s_SockClient->GetLastHorizAngle();
    printf("[Camera] Turning to %f\n", m_targetAngle);
	s_Gyro->Reset();
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 */
void TurnToAngleCamera::Execute() 
{
    float error = m_targetAngle - s_Gyro->GetAngle();
    m_integral += error;
	s_Drive->DriveRobot(0.0, -0.02 * error - 0.001 * m_integral);
}

/**
 * @brief Whether or not the command is finished. 
 * Make this return true when this Command no longer needs to run execute().
 * @return Bool, if the command is finished or not. 
 */
bool TurnToAngleCamera::IsFinished() 
{
	return WithinTolerance<float>(s_Gyro->GetAngle(), m_targetAngle, 1);
}

/**
 * @brief Finishes the command. Called once after isFinished returns true.
 */
void TurnToAngleCamera::End() 
{
	s_Drive->Stop();
	printf("At target horizontal angle.\n");
}

/**
 * @brief Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 */
void TurnToAngleCamera::Interrupted() 
{
	printf("Turn to angle interrupted!\n");
	End();
}
