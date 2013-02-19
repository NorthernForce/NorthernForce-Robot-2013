#include "OI.h"
#include "Commands/DisableEncoders.h"
#include "Commands/EnableEncoders.h"
#include "Commands/SetDrivePID.h"
#include "Commands/EnableGyro.h"
#include "Commands/DisableGyro.h"
#include "Commands/FlickFrisbee.h"
#include "Commands/LogPOT.h"
#include "Commands/PrepareShooter.h"
#include "Commands/ElevateShooterWithJoystick.h"

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
    m_driverStick.A.WhenPressed(new LogPOT());
	m_driverStick.LeftBumper.WhenPressed(new DisableGyro());
	m_driverStick.RightBumper.WhenPressed(new EnableGyro());

	m_manipulatorStick.Trigger.WhenPressed(new FlickFrisbee());
	m_manipulatorStick.Button3.WhenPressed(new PrepareShooter(kPyramidFrontSpeed, 
			kPyramidFrontAngle));
	m_manipulatorStick.Button2.WhenPressed(new PrepareShooter(kPyramidBackSpeed, 
			kPyramidBackAngle));
	m_manipulatorStick.Button4.WhenPressed(new PrepareShooter(kHangSpeed, kHangAngle));
	m_manipulatorStick.Button5.WhenPressed(new PrepareShooter(kFeederStationSpeed, 
			kFeederStationAngle));
	m_manipulatorStick.Button10.WhenPressed(new ElevateShooterWithJoystick());
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
Attack3Joystick& OI::GetManipulatorStick()
{
	return m_manipulatorStick;
}
