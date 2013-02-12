#include "LogFile.h"

/** 
 * @brief Private NI function needed to write to the VxWorks target 
 */
IMAQ_FUNC int Priv_SetWriteFileAllowed(UINT32 enable); 

/*
 * @brief Constructs a log file with the specified name. 
 * @param name The name of the file to create.
 */
LogFile::LogFile(const char* name)
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
 * @brief Write data to the log file. The data will 
 * automatically be terminated with a newline.
 * @param data The data to write to the file. 
 */
void LogFile::Write(const char* data)
{
	FILE* logFile = fopen(m_fileName,"a"); 
	fprintf(logFile, "%s\n", data);
	fclose(logFile);
}
