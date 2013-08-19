#ifndef LOGFILE_H
#define LOGFILE_H

#include "WPILib.h"
#include "../Robotmap.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/stat.h>

/**
 * A class for creating a versatile log file for any 
 * subsystem. This can be used to create a log file of
 * any name, and write data to it. It can also be used
 * to automatically create a timestamped CSV file 
 * for easier data collection. 
 * 
 * @author Arthur Lockman
 */
class LogFile
{
private:
	void SetDirectory(const char* directory);
	char m_fileName[32];
	bool m_timeStamp;
	char m_separator;
	bool m_autonewline;
public:
	LogFile(const char* name, bool autoNewline = true, bool timestamp = false, char separator = ',');
	~LogFile();
	void Write(const char* data, ...);
	int GetSize();
	void DeleteFile();
};

#endif
