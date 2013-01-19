#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Library.h"

/**
 * This class handles all operator input on the robot. All
 * joysticks, custom boards, and any other method of interacting
 * with real humans go in here. 
 */
class OI 
{
private:
	FRCXboxJoystick m_driverStick;
	FRCXboxJoystick m_manipulatorStick;
public:
	OI();
	FRCXboxJoystick& GetDriverStick();
	FRCXboxJoystick& GetManipulatorStick();
};

#endif
