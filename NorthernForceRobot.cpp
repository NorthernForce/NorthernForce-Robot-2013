#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Library.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/SpinupShooter.h"
#include "Commands/LogSpeed.h"
#include "Commands/ElevateShooter.h"

/**
 * This class controls the entire robot.
 */
class NorthernForceRobot : public IterativeRobot 
{
	
//	DriveTo AutonomousCommand;
	
private:
	LiveWindow *lw;
	AutonomousCommand *autoCommand;
    SpinupShooter* spinupCommand;
    LogSpeed* speedprinter;
    ElevateShooter* elevateCommand;

	
	/**
	 * @brief Initializes the robot.
	 */
	virtual void RobotInit() 
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		
		autoCommand = new AutonomousCommand();
        spinupCommand = new SpinupShooter(kPyramidBackSpeed);
        speedprinter = new LogSpeed();
        elevateCommand = new ElevateShooter(kPyramidBackAngle);

        switch (DriverStation::GetInstance()->GetAlliance())
        {
        case (DriverStation::kRed):
       		CommandBase::s_Log->LogMessage("Robot ready. On red alliance.\n");
       		break;
       	case (DriverStation::kBlue):
       		CommandBase::s_Log->LogMessage("Robot ready. On blue alliance.\n");
       		break;
       	case (DriverStation::kInvalid):
       		CommandBase::s_Log->LogMessage("Robot ready. Alliance color unknown.\n");
       		break;
        }
	}
	
	/**
	 * @brief Initializes autonomous mode.
	 */
	virtual void AutonomousInit() 
	{
		CommandBase::s_Log->LogMessage(kLogPriorityDebug, "Entering autonomous mode.");
		CommandBase::s_Gyro->Reset();
		CommandBase::s_Gyro->DoStationaryCalibration(10);
		
		Scheduler::GetInstance()->AddCommand(autoCommand);
		
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
		CommandBase::s_Log->LogMessage(kLogPriorityDebug, "Entering teleoperated mode.");
		CommandBase::s_Gyro->Reset();
		CommandBase::s_Gyro->DoStationaryCalibration(10);
		Scheduler::GetInstance()->AddCommand(spinupCommand);
		Scheduler::GetInstance()->AddCommand(elevateCommand);
		if (!SHOOTER_PID_ENABLE)
		{
			Scheduler::GetInstance()->AddCommand(speedprinter);
		}
	}
	
	/**
	 * @brief Executes during teleoperated mode. 
	 */
	virtual void TeleopPeriodic() 
	{
		Scheduler::GetInstance()->Run();
	}
	
	/**
	 * @brief Initializes disabled mode.
	 */
	virtual void DisabledInit()
	{
		CommandBase::s_Log->LogMessage(kLogPriorityDebug, "Robot disabled.");
		CommandBase::s_Gyro->Reset();
		CommandBase::s_Shooter->Stop();
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

