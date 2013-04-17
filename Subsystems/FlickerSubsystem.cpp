#include "FlickerSubsystem.h"
#include "../Robotmap.h"

FlickerSubsystem::FlickerSubsystem() : Subsystem("FlickerSubsystem"),
	m_rearLimit(kFlickerRearLimit),
	m_forwardLimit(kFlickerForwardLimit),
	m_flickerVictor(kFlickerVictorAddress),
	m_lock(kShooterLockRelayAddress, Relay::kForwardOnly)
{
	Lock();
}
    
void FlickerSubsystem::InitDefaultCommand() 
{
	//No default command.
}

/**
 * @brief Sets the flicker to turn forward.
 */
void FlickerSubsystem::Forward()
{
	m_flickerVictor.Set(-1.0);
}

/**
 * @brief Sets the flicker to turn backwards.
 */
void FlickerSubsystem::Reverse()
{
	m_flickerVictor.Set(1.0);
}

/**
 * @brief Stops the flicker.
 */
void FlickerSubsystem::Stop()
{
	m_flickerVictor.StopMotor();
}

/**
 * @brief Lock the shooter lock.
 */
void FlickerSubsystem::Lock()
{
	m_lock.Set(Relay::kOn);
}

/**
 * @brief Unlock the shooter lock.
 */
void FlickerSubsystem::Unlock()
{
	m_lock.Set(Relay::kOff);
}

/**
 * @brief Gets whether the forward limit is hit.
 * @return A bool, the state of the limit.
 */
bool FlickerSubsystem::GetForwardLimit()
{
	return m_forwardLimit.Get();
}

/**
 * @brief Gets whether the rear limit is hit.
 * @return A bool, the state of the limit.
 */
bool FlickerSubsystem::GetRearLimit()
{
	return m_rearLimit.Get();
}
