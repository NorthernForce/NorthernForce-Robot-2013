#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

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
 
#endif
