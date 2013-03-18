#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robotmap.h"
#include "../lib/LogFile.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief A logging system for the Robot. This log will log anything
 * to the netconsole, as well as save all logs to a logfile. What this
 * log system outputs depends on which log level is set at its initialization.
 * In addition, every log message that is passed in must have a log level 
 * attached to it. This way, the console doesn't get clogged up with 
 * non-critical messages unless testing is going on.
 *
 * @author arthurlockman
 * @see https://github.com/NorthernForce/Rebound-Rumble/blob/master/Project/Commands/LogAccelerometer.cpp
 */
class LogSystem: public Subsystem 
{
private:
	LogPriority m_logLevel;
	LogFile m_robotLogFile;
public:
	LogSystem(LogPriority level);
	void InitDefaultCommand();
	void LogMessage(LogPriority level, const char* message, ...);
	void LogMessage(const char* message, ...);
};

#endif
