#ifndef LOGFILE_H
#define LOGFILE_H

#include "WPILib.h"
#include "../Robotmap.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * A class for creating a versatile log file for any 
 * subsystem. This can be used to create a log file of
 * any name, and write data to it. 
 * 
 * @author Arthur Lockman
 */
class LogFile
{
private:
	void SetDirectory(const char* directory);
	char m_fileName[32];
public:
	LogFile(const char* name);
	~LogFile();
	void Write(const char* data, ...);
};

#endif
