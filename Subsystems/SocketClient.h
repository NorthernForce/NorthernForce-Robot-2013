#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <stdarg.h>

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Library.h"
#include "../CommandBase.h"

/**
 * A library for connecting the cRIO to a telnet
 * socket server. This class creates a thread
 * and reads strings from the telnet server and stores
 * them so that they can be read by other classes. 
 *
 * @author arthurlockman
 */
class SocketClient: public Subsystem 
{
private:
	int m_port;
	char* m_host;
	struct sockaddr_in sa;
	struct hostent hen;
	CameraData m_lastData;
	const SEM_ID m_socketSemaphore;
	Task m_socketConnectionTask;
	static void SocketConnectionTask(SocketClient& sock);
	bool Connect();
	bool Read();
	int sockfd;
	int sendln(const char* line);
	static const int sendTimeout = 0;
	
public:
	SocketClient(char* host, int port);
	~SocketClient();
	void InitDefaultCommand();
	void run();
	void errsys(char* err);
	const CameraData GetLastData();
};

#endif
