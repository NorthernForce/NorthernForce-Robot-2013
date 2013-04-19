#include "OI.h"
#include "Commands/DisableEncoders.h"
#include "Commands/EnableEncoders.h"
#include "Commands/SetDrivePID.h"
#include "Commands/EnableGyro.h"
#include "Commands/DisableGyro.h"
#include "Commands/FlickFrisbee.h"
#include "Commands/FlickFrisbee.h"
#include "Commands/LogPOT.h"
#include "Commands/PrepareShooter.h"
#include "Commands/ElevateShooter.h"
#include "Commands/ElevateShooterWithJoystick.h"
#include "Commands/ElevateShooterRelative.h"
#include "Commands/SpinupShooter.h"
#include "Commands/SpinShooter.h"
#include "Commands/StopShooter.h"
#include "Commands/UnlockShooter.h"
#include "Commands/LockShooter.h"

/**
 * @brief Initializes the operator interface.
 */
OI::OI() :
	m_driverStick(1),
	m_manipulatorStick(2)
{
	// Driver Joystick Buttons.
	m_driverStick.LeftBumper.WhenPressed(new DisableGyro());
	m_driverStick.RightBumper.WhenPressed(new EnableGyro());
	m_driverStick.B.WhenPressed(new PrepareShooter(kPyramidBackSpeed, kPyramidBackAngle));
	m_driverStick.X.WhenPressed(new FlickFrisbee());
	m_driverStick.A.WhenPressed(new UnlockShooter());
	m_driverStick.A.WhenReleased(new LockShooter());

	// Manipulator Joystick Buttons.
	m_manipulatorStick.Trigger.WhenPressed(new FlickFrisbee());
	m_manipulatorStick.Button2.WhenPressed(new UnlockShooter());
	m_manipulatorStick.Button2.WhenReleased(new LockShooter());
	m_manipulatorStick.Button4.WhenPressed(new PrepareShooter(kPyramidBackSpeed, kPyramidBackAngle));
	m_manipulatorStick.Button6.WhenPressed(new ElevateShooterRelative(-1.5));
	m_manipulatorStick.Button7.WhenPressed(new ElevateShooterRelative(1.5));
	m_manipulatorStick.Button10.WhenPressed(new PrepareShooter(kHangSpeed, kHangAngle));
	m_manipulatorStick.Button11.WhenPressed(new PrepareShooter(kFeederStationSpeed, kFeederStationAngle));
	m_manipulatorStick.Button9.WhenPressed(new ElevateShooter(0.0));
    m_manipulatorStick.Button8.WhenPressed(new StopShooter());
    m_manipulatorStick.Button7.WhileHeld(new SpinShooter(-1.0, false));
    
    // Smart Dashboard Buttons.
    SmartDashboard::PutData("Shoot", new FlickFrisbee());
    SmartDashboard::PutData("Raise Shooter 1.0 Degrees", new ElevateShooterRelative(1.0));
    SmartDashboard::PutData("Lower Shooter 1.0 Degrees", new ElevateShooterRelative(-1.0));
    SmartDashboard::PutData("Zero Shooter", new ElevateShooter(0.0));
    SmartDashboard::PutData("Unlock Shooter", new UnlockShooter());
    SmartDashboard::PutData("Lock Shooter", new LockShooter());
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
