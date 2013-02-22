#include "Aim.h"
#include "WPILib.h"
#include "../Library.h"
#include "../CommandBase.h"

#include "ElevateShooter.h"
#include "SpinupShooter.h"
#include "TurnToAngle.h"

Aim::Aim() 
{
	AddParallel(new ElevateShooter(CommandBase::s_SockClient->GetLastData().vertAngle));
        AddParallel(new TurnToAngle(CommandBase::s_Gyro->GetAngle() 
                + CommandBase::s_SockClient->GetLastData().horizAngle));
        //@TODO: Implement spinup speed based on distance.
	AddParallel(new SpinupShooter(kPyramidBackSpeed));
}
