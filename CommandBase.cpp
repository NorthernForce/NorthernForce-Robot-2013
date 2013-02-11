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

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
LogSystem* CommandBase::s_Log = NULL;
DriveSubsystem* CommandBase::s_Drive = NULL;
SocketClient* CommandBase::s_SockClient = NULL;

/**
 * @brief Initializes the commandbase. Creates instances of
 * all the subsystems for use elsewhere on the robot.
 */
void CommandBase::init() 
{
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	oi = new OI();
	s_Log = new LogSystem(kLogPrioritySystem);
	s_Drive = new DriveSubsystem();
	s_SockClient = new SocketClient("10.1.72.13",1180);
}
