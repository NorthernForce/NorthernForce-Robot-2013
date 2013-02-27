#include "Aim.h"
#include "WPILib.h"
#include "../Library.h"
#include "../CommandBase.h"

#include "ElevateShooter.h"
#include "SpinupShooter.h"
#include "TurnToRelativeAngle.h"

Aim::Aim() 
{
	AddParallel(new ElevateShooter(CommandBase::s_SockClient->GetLastData().vertAngle));
        AddParallel(new TurnToRelativeAngle(CommandBase::s_Gyro->GetAngle() 
                + CommandBase::s_SockClient->GetLastData().horizAngle));
        //@TODO: Implement spinup speed based on distance.
	AddParallel(new SpinupShooter(kPyramidBackSpeed));
}
