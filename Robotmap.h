#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

 /*
  * @brief The button ports on the XBox Joystick, as interpreted by the cRIO.
  */
enum XBoxJoystickButtonPort
{
	kXBoxButtonA = 1,
	kXBoxButtonB = 2,
	kXBoxButtonX = 3,
	kXBoxButtonY = 4,
	kXBoxButtonLeft = 5,
	kXBoxButtonRight = 6,
	kXBoxButtonBack = 7,
	kXBoxButtonStart = 8,
	kXBoxButtonLeftJoystick = 9,
	kXBoxButtonRightJoystick = 10,
};

/*
 * @brief The button ports on the Attack 3 Joystick.
 */
enum Attack3JoystickPort
{
 	kAttackJoystickButtonTrigger = 1, 
 	kAttackJoystickButton2 = 2,
 	kAttackJoystickButton3 = 3,
 	kAttackJoystickButton4 = 4,
 	kAttackJoystickButton5 = 5,
 	kAttackJoystickButton6 = 6,
 	kAttackJoystickButton7 = 7,
 	kAttackJoystickButton8 = 8,
 	kAttackJoystickButton9 = 9,
 	kAttackJoystickButton10 = 10,
 	kAttackJoystickButton11 = 11,
	kAttackJoystickButton12 = 12,
};
 
/**
 * @brief The different possible levels of debug logging.
 */
enum LogPriority
{
	kLogPrioritySystem = 1,
 	kLogPriorityDebug = 2,
 	kLogPriorityError = 3
};
 
/**
 * @brief The addresses of the jaguars on the CAN bus.
 */
enum JaguarAddresses
{
	kFrontRightJaguarAddress = 1,
	kFrontLeftJaguarAddress = 2,
	kRearRightJaguarAddress = 3,
    kRearLeftJaguarAddress = 4,
    kShooterJaguarAddress = 5,
};

enum DigitalAdresses 
{
    kShooterWheelLightSensorAddress = 1,
};

enum PWMAddresses 
{
    kShooterElevatorVictorAddress = 1,
};

/**
 * @brief The addresses of the relays
 */
enum RelayAdresses 
{
	kShooterFlickerRelayAddress = 1,
};

enum AnalogChannels 
{
    kGyroChannel = 1,
	kShooterElevatorPotChannel = 3,
};

/**
 * @brief A structure to hold a target data.
 */
struct Target
{
	float vertAngle;
	float horizAngle;
	float distance;
};

/**
 * @brief A structure to hold the camera-estimated position data.
 */
struct RobotPosition
{
	float x;
	float y;
	float theta;
	float stdDevX;
	float stdDevY;
	float stdDevTheta;
};

static const float kDriveRamp = 0.4;
static const float kDriveVelocityLimit = 1.0;
static const float kDriveTolerance = 0.2;
static const float kDriveThereTolerance = 0.1;

//Gyro Control Variables
static const int kGyroSlot = 1;
static const int kGyroTemp = 2;
static const float kGyroSensitivity = 0.007;

static const float kWheelEncoderRatio = 0.073146875;   //Inches per "tick" of the Encoder
static const double kDistanceBand = 6;
static const float kAngularRateBand = 0.1;
static const float kSlowAutoSpeed = 0.1;
static const float kFastAutoSpeed = 0.3;
static const float kSlowAngularRate = 0.1;
static const float kFastAngularRate = 0.3;

static const float kShooterSpinupSpeed = 0.5;
static const float kShooterIdleSpeed = 0.0;
static const float kShooterSpinupTolerance = 0.1;

static const float kShooterP = 1.0;
static const float kShooterI = 0.0;
static const float kShooterD = 0.0;

static const float kShooterElevatorP = 0.25;
static const float kShooterElevatorI = 0.0001;
static const float kShooterElevatorD = 0.0;

// Shooter Elevator Constants
static const float kElevatorDegreesPerVolt = 54.054054;
static const float kElevatorZero = 3.742;

static const float kDeadbandLimit = 0.3;

static const float kElevatorMaxAngle = 33.5;
static const float kElevatorMinAngle = 0.0;

//Shooter position constants
static const float kPyramidFrontSpeed = -.742;
static const float kPyramidFrontAngle = 34.455;
static const float kPyramidBackSpeed = -.367;
static const float kPyramidBackAngle = 23.234;
static const float kFeederStationSpeed = -.425;
static const float kFeederStationAngle = 17.236;
static const float kHangSpeed = -.18;
static const float kHangAngle = 27.234;

/**
 * @brief Tells whether or not a value is within a certain tolerance of another value.
 * @param value The value to check.
 * @param desiredValue The value to check value against.
 * @param tolerance The desired tolerance.
 * @return A boolean, whether or not the value is within the tolerance.
 */
template <typename T>
inline bool WithinTolerance(T value, T desiredValue, T tolerance)
{
	if ((value < desiredValue + tolerance) && (value > desiredValue - tolerance))
		return true;
	else
		return false;
};

/**
 * @brief Limits a value to a defined limit.
 * @param input The input value.
 * @param max The value to limit it to.
 * @return The limited value. 
 */
template <typename T> 
inline T Limit(T input, T max)
{
    if (input > max)
    {
        return max;
    } else if (input < -max)
    {
        return -max;
    }
    return input;
};

#endif
