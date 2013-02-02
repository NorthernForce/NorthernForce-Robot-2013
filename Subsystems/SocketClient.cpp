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
	return true;
}

/**
 * @brief Reads data from the socket server.
 */
bool SocketClient::Read()
{
	int n;
	char recvline[1024];
	
	n=read(sockfd,recvline,255);
	{
		//printf("Read %d bytes\n",n);
		recvline[n]=0;
		printf("%s",recvline);
		{
			const Synchronized sync(m_socketSemaphore);
			strcpy(m_lastData, recvline);
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
 * @brief Gets the last data that was read from the socket connection.
 * @return A string, the last data from the connection. 
 */
const char* SocketClient::GetLastData()
{
	char* ret;
	{
		const Synchronized sync (m_socketSemaphore);
		strcpy(ret, m_lastData);
	}
	return ret;
}
