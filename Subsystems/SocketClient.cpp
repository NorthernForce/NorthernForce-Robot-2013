#include "SocketClient.h"
#include "../Robotmap.h"

/**
 * @brief Constructs the SocketClient class. This 
 * creates the connection, and starts the socket 
 * connection thread.
 * @param host The host name of the server to connect 
 * to (a string) (ex: "10.1.72.2").
 * @param port The port to connect to on the server (ex: 9999).
 */
SocketClient::SocketClient(char* host, int port) : 
	Subsystem("SocketClient"),
	m_port(port),
	m_host(host),
	sa(),
	hen(),
	m_socketSemaphore(semBCreate (SEM_Q_PRIORITY, SEM_FULL)),
	m_socketConnectionTask("SocketConnection", (FUNCPTR)SocketClient::SocketConnectionTask, Task::kDefaultPriority + 10)
{
	printf("Connecting to %s:%d...\n",m_host,m_port);	
	
	char buff[255];
	strcpy(buff, m_host);
	char* _tmp;
	_tmp = strtok(buff,".");
	
	char* list =  new char[4];
	list[0] = atoi(_tmp);
	_tmp = strtok(NULL,".");
	list[1] = atoi(_tmp);
	_tmp = strtok(NULL,".");
	list[2] = atoi(_tmp);
	_tmp = strtok(NULL,".");
	list[3] = atoi(_tmp);
	
	hen.h_name = m_host;
	hen.h_aliases = NULL;
	hen.h_addrtype = 2;
	hen.h_length = 4;
	hen.h_addr_list = &list;
	
	memset(&sa,0,sizeof sa);
	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);
	memcpy(&sa.sin_addr.s_addr, hen.h_addr_list[0], hen.h_length);

	m_socketConnectionTask.Start(reinterpret_cast<UINT32> (this));
}
    
/**
 * @brief Destroys the socket client, and its data semaphore.
 */
SocketClient::~SocketClient()
{
	semDelete(m_socketSemaphore);
}

/**
 * @brief Initializes the default command for the subsystem.
 */
void SocketClient::InitDefaultCommand() 
{
	
}

/**
 * @brief The method that the SocketConnectionTask calls
 * to begin running. 
 */
void SocketClient::SocketConnectionTask(SocketClient &sock)
{
	sock.run();
}

/**
 * @brief Handles connection to the socket server.
 */
void SocketClient::run()
{
	int n;
	while (1)
	{
		if (Connect())
		{
			while (Read())
			{
				n = 0;
			}
		}
		
		n++;
		if (n > 10)
		{
			if (n == 11)
				errsys("Throttling reconnect to every 10s...\n");
			Wait(10.0);
		}
		else if (n > 5)
		{
			if (n == 6)
				errsys("Throttling reconnect to every 5s...\n");
			Wait(5.0);
		}
		else if (n <= 5)
		{
			Wait(1.0);
		}
	}
}

/**
 * @brief Connects to the socket server.
 */
bool SocketClient::Connect()
{
	errsys("Trying to conect...");
	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		errsys("Socket error!");
		return false;
	}

	if(connect(sockfd,(SOCKADDR*)&sa,sizeof sa) < 0)
	{
		errsys("Connection error!");
		return false;
	}
	
	errsys("Connected!");
	StartDataStream(1000);
	return true;
}

/**
 * @brief Reads data from the socket server.
 */
bool SocketClient::Read()
{
	int n;
	char recvline[1024];
	
	n = read(sockfd,recvline,1024);
	{
		//printf("Read %d bytes\n",n);
		recvline[n]=0;
		char cmd[5];
		strncpy(cmd, recvline, 4);
		cmd[4] = 0;
		if (!strcasecmp(cmd,"falg"))
		{
			printdebug("Communications with Pi OK.\n");
		}
		else if (!strcasecmp(cmd,"came"))
		{
			//Second communications check. 
		}
		else if (!strcasecmp(cmd,"CAMC"))
		{
			//printf("%s",recvline+5);
			//Parse here.
			char* _tmpLn = strtok(recvline+5, ",");
			CameraData _tmpCdata;
			
			_tmpCdata.angle1 = atof(_tmpLn);
			_tmpLn = strtok(NULL, ",");
			_tmpCdata.angle2 = atof(_tmpLn);
			_tmpLn = strtok(NULL, ",");
			_tmpCdata.distance = atof(_tmpLn);
			_tmpLn = strtok(NULL, ",");
			_tmpCdata.orientation = atof(_tmpLn);
			_tmpLn = strtok(NULL, ",");
			_tmpCdata.x = atof(_tmpLn);
			_tmpLn = strtok(NULL, ",");
			_tmpCdata.y = atof(_tmpLn);
			_tmpLn = strtok(NULL, ",");
			_tmpCdata.processingTime = atof(_tmpLn);
			
			{
				const Synchronized sync(m_socketSemaphore);
				m_lastData = _tmpCdata;
			}
		}
		else
		{
			printf("WARNING: received unexpected command: [%s]\n",cmd);
		}
	}
	if(n<1)
	{
		errsys("Read error!");
		return false;
	}
	
	return true;
}

/**
 * @brief Prints a system error to the log system.
 * @param err The error to print to the log.
 */
void SocketClient::errsys(char* err)
{
	CommandBase::s_Log->LogMessage(err,kLogPriorityError);
}

/**
 * @brief Prints a debug message to the log system.
 * @param err The message to print to the log.
 */
void SocketClient::printdebug(char* err)
{
	CommandBase::s_Log->LogMessage(err,kLogPriorityDebug);
}

/**
 * @brief Gets the last data that was read from the socket connection.
 * @return A string, the last data from the connection. 
 */
const CameraData SocketClient::GetLastData()
{
	const Synchronized sync (m_socketSemaphore);
	return m_lastData;
}

/**
 * @brief Starts the stream of data from the server.
 * @param updateInterval The interval at which to receive camera updates. 
 */
int SocketClient::StartDataStream(int updateInterval)
{
	char msg[80];
	sprintf(msg, "CAMC %i", updateInterval);
	return sendln(msg);
}

/**
 * @brief Stops the stream of data from the server. 
 */
int SocketClient::StopDataStream()
{
	return sendln("STOP");
}

/**
 * @brief Sends a line of data back to the server. 
 * @param line The line of data to send.
 * @return The number of bytes sent. -1 if error. 
 */
int SocketClient::sendln(const char* line)
{
	int length = strlen(line);
	int sent = send(sockfd, line, length, sendTimeout);
	send(sockfd, "\n", 1, sendTimeout);
	
	//printf("Sent %i bytes.\n",sent);
	if (sent == length)
		return length;
	else if (sent == -1)
	{
		errsys("Error sending data to server. 0 bytes sent.");
		return -1;
	}
	else if (sent < length)
	{
		errsys("Error sending data to server. Some bytes sent.");
		return sent;
	}
	
	return -1;
}
