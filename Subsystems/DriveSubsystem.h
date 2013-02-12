#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Library.h"

/**
 * This is the class which controls the driving of the robot. This
 * is a subsystem, and behaves just like every other subsystem
 * in the code library. Rather than using a different class
 * for drive like last year, it is better to contain it all
 * inside this one class. 
 * 
 * @author arthurlockman
 */
class DriveSubsystem: public Subsystem 
{
private:
	RampedCANJaguar m_frontLeftMotor;
	RampedCANJaguar m_frontRightMotor;
	RampedCANJaguar m_rearLeftMotor;
	RampedCANJaguar m_rearRightMotor;
	RobotDrive m_drive;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	void DriveRobot(FRCXboxJoystick& stick);
	void DriveRobot(Attack3Joystick& moveStick, Attack3Joystick& rotateStick);
	void DriveRobot(float moveValue, float rotateValue);
	void Stop();
};

#endif
