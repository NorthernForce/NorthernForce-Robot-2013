#include "LogSystem.h"
#include "../Robotmap.h"

/** 
 * @brief Private NI function needed to write to the VxWorks target 
 */
IMAQ_FUNC int Priv_SetWriteFileAllowed(UINT32 enable); 

/**
 * @brief Constructs the Logging subsystem.
 * @param level The level of logs to save to the logfile and print to
 * the console. 
 * 
 * @author Arthur Lockman
 */
LogSystem::LogSystem(LogPriority level) : 
	Subsystem("LogSystem") , 
	m_logLevel(level),
	m_robotLogFile("RobotLog.txt")
{
	this->LogMessage(kLogPriorityError, "-----System Boot: Starting New Log-----");
}
    
/**
 * @brief Handles the creation of the default command for this subsystem.
 * 
 * @author WPILib
 */
void LogSystem::InitDefaultCommand() 
{
	
}

/**
 * @brief Logs a message to the logfile and to the console.
 * @param level The level of log that this message has attached to it.
 * @param message The message to be logged.
 * 
 * @author Arthur Lockman
 */
void LogSystem::LogMessage(LogPriority level, const char* message, ...)
{
	va_list argptr;
    va_start(argptr, message);

	if (level >= m_logLevel)
	{
		char _tmp[200];
		vsprintf(_tmp, message, argptr);
		m_robotLogFile.Write("%.3f:  %s\n", GetFPGATime() / 1000000.0, _tmp);

		printf("%.3f:  %s\n", GetFPGATime() / 1000000.0, _tmp);
	}

	va_end(argptr); 
}
/**
 * @brief Logs a message to the logfile with the default priority level.
 * @param message The message to be logged.
 */
void LogSystem::LogMessage(const char* message, ...)
{
	va_list argptr;
    va_start(argptr, message);
    char _tmp[200];
    vsprintf(_tmp, message, argptr);

    this->LogMessage(kLogPriorityDebug, _tmp);

   	va_end(argptr); 
}

