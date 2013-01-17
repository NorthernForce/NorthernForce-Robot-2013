#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Library.h"

/**
 * This class controls the entire robot.
 */
class NorthernForceRobot : public IterativeRobot 
{
private:
	LiveWindow *lw;
	
	/**
	 * @brief Initializes the robot.
	 */
	virtual void RobotInit() 
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
	}
	
	/**
	 * @brief Initializes autonomous mode.
	 */
	virtual void AutonomousInit() 
	{
		
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
		
	}
	
	/**
	 * @brief Executes during teleoperated mode. 
	 */
	virtual void TeleopPeriodic() 
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(NorthernForceRobot);

