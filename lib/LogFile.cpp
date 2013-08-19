#include "LogFile.h"

/** 
 * @brief Private NI function needed to write to the VxWorks target 
 */
IMAQ_FUNC int Priv_SetWriteFileAllowed(UINT32 enable); 

/*
 * @brief Constructs a log file with the specified name. 
 * @param name The name of the file to create.
 * @param autoNewline Whether or not to automatically append each line with a newline.
 * Default is true.
 * @param timestamp Whether or not to add a timestamp to the start of each line.
 * Useful for data logging. 
 * @param separator What to separate the timestamp and data with.
 */
LogFile::LogFile(const char* name, bool autoNewline, bool timestamp, char separator) :
	m_timeStamp(timestamp),
	m_separator(separator),
	m_autonewline(autoNewline)
{
	printf("Opening new logfile with name %s\n",name);
	sprintf(m_fileName, name);
	Priv_SetWriteFileAllowed(1);
}

/*
 * @brief Destroys the log file object. 
 */
LogFile::~LogFile()
{
	delete(m_fileName);
}

/**
 * @brief Write data to the log file.
 * @param data The data to write to the file. 
 */
void LogFile::Write(const char* data, ...)
{
	FILE* logFile = fopen(m_fileName,"a"); 

	va_list args;
    va_start(args, data);
    
    if (m_timeStamp) { fprintf(logFile, "%i %c ", GetFPGATime(), m_separator); }
	vfprintf(logFile, data, args);
	if (m_autonewline) { fprintf(logFile, "\n"); }
	
	va_end (args);
	fclose(logFile);
}

/**
 * @brief Returns the file size, in bytes, of the logfile.
 * @return The file size, in bytes.
 */
int LogFile::GetSize()
{	
	struct stat _tmp;
	stat(m_fileName, &_tmp);
	
	return (int)_tmp.st_size;
}

/**
 * @brief Deletes the data file saved by this log. 
 */
void LogFile::DeleteFile()
{
	if (remove(m_fileName) == 0)
		printf("File \"%s\" successfully removed.\n", m_fileName);
	else
		printf("Error deleting file: no such file or directory.\n");
}
