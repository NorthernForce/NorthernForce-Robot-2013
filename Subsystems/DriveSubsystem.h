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
    
    float m_driveErrAccumulator;
    LogFile m_DriveLog;
    bool m_loggingEnabled;
    bool m_gyroEnabled;
    bool m_encodersEnabled;

    static const double kDriveSpinP = 1.75;
    static const double kDriveSpinI = 0.15;
    static const double kDriveSpinD = 0.0;
    static const double kDriveP = 1.0;
    static const double kDriveI = 0.0;
    static const double kDriveD = 0.0;
    static const double kDrivePosP = 0.0;
    static const double kDrivePosI = 0.0;
    static const double kDrivePosD = 0.0;
    static const int kEncoderPulsesPerRev = 256;

    static const float kDriveMaxOutputVoltage = 12.0;

public:
	DriveSubsystem();
	void InitDefaultCommand();
	void DriveRobot(FRCXboxJoystick& stick);
	void DriveRobot(Attack3Joystick& moveStick, Attack3Joystick& rotateStick);
	void DriveRobot(float moveValue, float rotateValue);
	void Stop();
	void EnableGyro();
	void DisableGyro();
	void EnableLogging();
	void DisableLogging();
	double GetAvgDistance();
	void EnableEncoders();
	void DisableEncoders();
	void ChangeDrivePID(float p, float i, float d);
	void EnablePositionMode();
	
	/**
	 * @brief Gets whether or not the encoders are enabled.
	 * @return Whether or not the encoders are enabled.
	 */
	inline bool EncodersEnabled()
	{
		return m_encodersEnabled;
	}

	/**
	 * @brief Gets whether or not the gyro is enabled.
	 * @return Whether or not the gyro is enabled.
	 */
	inline bool GyroEnabled()
	{
		return m_gyroEnabled;
	}
};

#endif
