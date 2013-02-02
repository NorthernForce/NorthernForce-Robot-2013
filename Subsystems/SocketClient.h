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

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Library.h"
#include "../CommandBase.h"

/**
 *
 *
 * @author arthurlockman
 */
class SocketClient: public Subsystem 
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	SocketClient();
	void InitDefaultCommand();
	void run();
	void errsys(char* err);
};

#endif
