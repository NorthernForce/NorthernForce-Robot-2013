#include "PulseBasedEncoder.h"

/**
 * @brief Constructor for the Pulse encoder.
 * @param channel The digital channel that the encoder is connected to.
 * @param pulsesPerRev The number of pulses per one revolution. Default 1.
 * @param distancePerPulse The distance traveled per each pulse. 
 */
PulseBasedEncoder::PulseBasedEncoder(int channel, int pulsesPerRev, double distancePerPulse) :
	c(channel),
	m_distPerPulse(distancePerPulse),
	m_pulsesPerRev(pulsesPerRev),
	m_resetCounter(0)
{
	c.Start();
}

/**
 * @brief Destroys the encoder object.
 */
PulseBasedEncoder::~PulseBasedEncoder()
{
	c.Stop();
}

/**
 * @brief Returns the veolcity of the encoder.
 * @return A double, the velocity in RPM.
 */
double PulseBasedEncoder::GetVelocity()
{
	double per = c.GetPeriod();
	if (m_resetCounter > 10) { c.Reset(); }
	else { m_resetCounter++; }
	return ((60.0 / per) * (double)m_pulsesPerRev);
}

/**
 * @brief Sets the distance traveled each pulse.
 * @param distancePerPulse The distance traveled each pulse.  
 */
void PulseBasedEncoder::SetDistancePerPulse(double distancePerPulse)
{
	m_distPerPulse = distancePerPulse;
}

/**
 * @brief Sets the number of pulses per one revolution.
 * @param pulsesPerRev The number of pulses per each revolution. 
 */
void PulseBasedEncoder::SetPulsesPerRevolution(int pulsesPerRev)
{
	m_pulsesPerRev = pulsesPerRev;
}

/**
 * @brief Gets the distance traveled by the encoder. WARNING: Does not know
 * which direction the encoder has traveled.
 * @return A double, the distance traveled. 
 */
double PulseBasedEncoder::GetDistance()
{
	return c.Get() * m_distPerPulse;
}

/**
 * @brief Gets the most recent time per pulse.
 * @return A double, the period in seconds of the last pulse.
 */
double PulseBasedEncoder::GetPeriod()
{
	return c.GetPeriod();
}

/**
 * @brief Resets the encoder to zero.
 */
void PulseBasedEncoder::Reset()
{
	c.Stop();
	c.Reset();
	c.Start();
}
