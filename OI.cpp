#include "OI.h"
#include "Commands/DisableEncoders.h"
#include "Commands/EnableEncoders.h"
#include "Commands/SetDrivePID.h"

/**
 * @brief Initializes the operator interface.
 */
OI::OI() :
	m_driverStick(1),
	m_manipulatorStick(2)
{
	// Process operator interface input here.
	m_driverStick.Back.WhenPressed(new DisableEncoders());
	m_driverStick.Start.WhenPressed(new EnableEncoders());
	m_driverStick.Y.WhenPressed(new SetDrivePID());
}

/**
 * @brief Gets the driver joystick.
 * @return A reference to the driver's joystick.
 */
FRCXboxJoystick& OI::GetDriverStick()
{
	return m_driverStick;
}

/**
 * @brief Gets the manipulator joystick.
 * @return A reference to the manipulator joystick. 
 */
FRCXboxJoystick& OI::GetManipulatorStick()
{
	return m_manipulatorStick;
}
