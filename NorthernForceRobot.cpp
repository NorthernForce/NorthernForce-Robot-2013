#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Library.h"
#include "Commands/DriveTo.h"

/**
 * This class controls the entire robot.
 */
class NorthernForceRobot : public IterativeRobot 
{
	
//	DriveTo AutonomousCommand;
	
private:
	LiveWindow *lw;
	DriveTo    *autoGoTo;

	
	/**
	 * @brief Initializes the robot.
	 */
	virtual void RobotInit() 
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		
		autoGoTo = new DriveTo(36, 0);

	}
	
	/**
	 * @brief Initializes autonomous mode.
	 */
	virtual void AutonomousInit() 
	{
		CommandBase::s_Log->LogMessage("Entering autonomous mode.",kLogPriorityDebug);
		CommandBase::s_Gyro->Reset();
		CommandBase::s_Gyro->DoStationaryCalibration(10);
		
		autoGoTo->Start();
		
	}
	
	/**
	 * @brief Executes during autonomous mode.
	 */
	virtual void AutonomousPeriodic() 
	{
		Scheduler::GetInstance()->Run();
	}
	
	/**
	 * @brief Initializes teleoperated mode.
	 */
	virtual void TeleopInit() 
	{
		CommandBase::s_Log->LogMessage("Entering teleoperated mode.",kLogPriorityDebug);
		CommandBase::s_Gyro->Reset();
		CommandBase::s_Gyro->DoStationaryCalibration(10);
	}
	
	/**
	 * @brief Executes during teleoperated mode. 
	 */
	virtual void TeleopPeriodic() 
	{
		Scheduler::GetInstance()->Run();
		//printf("%f\n",CommandBase::s_Gyro->GetRate());
	}
	
	/**
	 * @brief Initializes disabled mode.
	 */
	virtual void DisabledInit()
	{
		CommandBase::s_Log->LogMessage("Robot disabled.",kLogPriorityDebug);
		CommandBase::s_Gyro->Reset();
	}
	
	/**
	 * @brief Executes when the robot is disabled.
	 */
	virtual void DisabledPeriodic()
	{
		
	}
	
	virtual void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(NorthernForceRobot);

