#include <WPILib.h>

/**
 * An encoder that is based off of some pulse device, like a 
 * proximity sensor connected to a bolt on a wheel. This encoder
 * can calculate the velocity and distance traveled of the 
 * encoder.
 * 
 * @author Arthur Lockman
 */
class PulseBasedEncoder
{
public:
	PulseBasedEncoder(int channel, int pulsesPerRev = 1, double distancePerPulse = 1.0);
	~PulseBasedEncoder();
	double GetVelocity();
	void SetDistancePerPulse(double distancePerPulse);
	void SetPulsesPerRevolution(int pulsesPerRev);
	double GetPeriod();
	double GetDistance();
	void Reset();
private:
	Counter c;
	double m_distPerPulse;
	int m_pulsesPerRev;
	int m_resetCounter;
};
