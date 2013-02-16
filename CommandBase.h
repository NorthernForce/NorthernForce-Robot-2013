#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "OI.h"
#include "Library.h"
#include "Subsystems/LogSystem.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/SocketClient.h"
#include "Subsystems/GyroSubsystem.h"
#include "Subsystems/RobotNav.h"
#include "Subsystems/ShooterElevatorSubsystem.h"

class SocketClient;
class GyroSubsystem;

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command 
{
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static LogSystem *s_Log;
	static DriveSubsystem *s_Drive;
	static SocketClient *s_SockClient;
	static GyroSubsystem *s_Gyro;
	static RobotNav *s_Nav;
	static ShooterElevatorSubsystem *s_ShooterElevator;
};

#endif
