#include "Aim.h"
#include "WPILib.h"
#include "../Library.h"
#include "../CommandBase.h"

#include "ElevateShooterCamera.h"
#include "SpinupShooter.h"
#include "TurnToAngleCamera.h"

/*
float GetLastVertAngle() {
    return CommandBase::s_SockClient->GetLastVertAngle();
}

float GetLastHorizAngle() {
    return CommandBase::s_SockClient->GetLastHorizAngle();
}
*/
Aim::Aim() 
{
    AddParallel(new SpinupShooter(kPyramidBackSpeed));
    AddParallel(new ElevateShooterCamera());
    AddParallel(new TurnToAngleCamera(), 5.0);
//	AddParallel(new ElevateShooterRelative(&GetLastVertAngle));
        //AddParallel(new TurnToRelativeAngle(//CommandBase::s_Gyro->GetAngle() 
        //        /*+*/ &GetLastHorizAngle));
        //@TODO: Implement spinup speed based on distance.
	//AddParallel(new SpinupShooter(kPyramidBackSpeed));
}
