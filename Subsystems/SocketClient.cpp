#include "SocketClient.h"
#include "../Robotmap.h"

SocketClient::SocketClient() : Subsystem("SocketClient") 
{
	
}
    
void SocketClient::InitDefaultCommand() 
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void SocketClient::run()
{
	int sockfd;
	int n;
	char recvline[255];
	int port = 9999;
	char host[255] = "10.1.72.12";
	struct sockaddr_in sa;
	struct hostent hen;
	char* list = new char[4];
	printf("connecting to host:port %s:%d\n",host,port);
	
	list[0] = 10;
	list[1] = 1;
	list[2] = 72;
	list[3] = 12;
	
	hen.h_name = "10.1.72.12";
	hen.h_aliases = NULL;
	hen.h_addrtype = 2;
	hen.h_length = 4;
	hen.h_addr_list = &list;
	
	memset(&sa,0,sizeof sa);
	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);
	memcpy(&sa.sin_addr.s_addr, hen.h_addr_list[0], hen.h_length);

	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
		errsys("socket error");

	if(connect(sockfd,(SOCKADDR*)&sa,sizeof sa) < 0)
		errsys("connect error");
	n=read(sockfd,recvline,255);
	{
		printf("Read %d bytes\n",n);
		recvline[n]=0;
		printf("%s",recvline);
	}
	if(n<0)
		errsys("read error");
}

void SocketClient::errsys(char* err)
{
	CommandBase::s_Log->LogMessage(err,kLogPriorityError);
}
