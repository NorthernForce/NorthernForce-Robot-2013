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
#include "Commands/FlickFour.h"

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
	m_driverStick.Back.WhenPressed(new ElevateShooterRelative(-1.0));
	m_driverStick.Start.WhenPressed(new ElevateShooterRelative(1.0));
	m_driverStick.B.WhenPressed(new PrepareShooter(kPyramidBackSpeed, kPyramidBackAngle));
	m_driverStick.X.WhenPressed(new FlickFrisbee(true));
	m_driverStick.A.WhenPressed(new UnlockShooter());
	m_driverStick.A.WhenReleased(new LockShooter());
	m_driverStick.Y.WhenPressed(new StopShooter());
	
	//DEMO MODE: Uncomment for deomonstrations.
//	m_driverStick.B.WhenPressed(new SpinupShooter(-0.4, true));
//	m_driverStick.Back.WhenPressed(new ElevateShooterRelative(-1.0));
//	m_driverStick.Start.WhenPressed(new ElevateShooterRelative(1.0));
//	m_driverStick.X.WhenPressed(new FlickFrisbee(false));
//	m_driverStick.A.WhenPressed(new UnlockShooter());
//	m_driverStick.A.WhenReleased(new LockShooter());
//	m_driverStick.LeftBumper.WhenPressed(new DisableGyro());
//	m_driverStick.RightBumper.WhenPressed(new EnableGyro());

	// Manipulator Joystick Buttons.
	m_manipulatorStick.Trigger.WhenPressed(new FlickFrisbee(true));
	m_manipulatorStick.Button2.WhenPressed(new UnlockShooter());
	m_manipulatorStick.Button2.WhenReleased(new LockShooter());
	m_manipulatorStick.Button3.WhenPressed(new FlickFour(kPyramidBackSpeed, kPyramidBackAngle));
	m_manipulatorStick.Button4.WhenPressed(new PrepareShooter(kPyramidBackSpeed, kPyramidBackAngle));
	m_manipulatorStick.Button6.WhenPressed(new ElevateShooterRelative(1.0));
	m_manipulatorStick.Button7.WhenPressed(new ElevateShooterRelative(-1.0));
    m_manipulatorStick.Button8.WhenPressed(new StopShooter());
	m_manipulatorStick.Button9.WhenPressed(new ElevateShooter(0.0));
	m_manipulatorStick.Button10.WhenPressed(new PrepareShooter(kHangSpeed, kHangAngle));
	m_manipulatorStick.Button11.WhenPressed(new PrepareShooter(kFeederStationSpeed, kFeederStationAngle));


    
    // Smart Dashboard Buttons.
    SmartDashboard::PutData("Shoot", new FlickFrisbee(true));
    SmartDashboard::PutData("Raise Shooter 1.0 Degrees", new ElevateShooterRelative(1.0));
    SmartDashboard::PutData("Lower Shooter 1.0 Degrees", new ElevateShooterRelative(-1.0));
    SmartDashboard::PutData("Zero Shooter", new ElevateShooter(0.0));
    SmartDashboard::PutData("Unlock Shooter", new UnlockShooter());
    SmartDashboard::PutData("Lock Shooter", new LockShooter());
    SmartDashboard::PutData("Prepare for Tower Shooting", new PrepareShooter(kPyramidBackSpeed, kPyramidBackAngle));
    SmartDashboard::PutData("Prepare for Feeder Shooting", new PrepareShooter(kFeederStationSpeed, kFeederStationAngle));
    SmartDashboard::PutData("Prepare for Hanging Shooting", new PrepareShooter(kHangSpeed, kHangAngle));
    SmartDashboard::PutData("Shoot 4", new FlickFour(kPyramidBackSpeed, kPyramidBackAngle));
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
