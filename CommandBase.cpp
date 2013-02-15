#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include <string>

/**
 * @brief Initializes the command base.
 * @param name The name of the item which is extending commandbase.
 */
CommandBase::CommandBase(const char *name) : Command(name) 
{
	
}

CommandBase::CommandBase() : Command() 
{
	
}

OI* CommandBase::oi = NULL;
LogSystem* CommandBase::s_Log = NULL;
DriveSubsystem* CommandBase::s_Drive = NULL;
SocketClient* CommandBase::s_SockClient = NULL;
GyroSubsystem* CommandBase::s_Gyro = NULL;
RobotNav* CommandBase::s_Nav = NULL;

/**
 * @brief Initializes the commandbase. Creates instances of
 * all the subsystems for use elsewhere on the robot.
 */
void CommandBase::init() 
{
	oi = new OI();
	s_Log = new LogSystem(kLogPrioritySystem);
	s_Drive = new DriveSubsystem();
	s_SockClient = new SocketClient("10.1.72.11",1180);
	s_Gyro = new GyroSubsystem(kGyroSlot, kGyroChannel, kGyroTemp, kGyroSensitivity);
	s_Nav  = new RobotNav();
}
