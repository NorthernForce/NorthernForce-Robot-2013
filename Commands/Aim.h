#ifndef AIMCOMMAND_H
#define AIMCOMMAND_H

#include "Commands/CommandGroup.h"

/**
 * A command group which aims the robot at the target 
 * that the camera can find. 
 *
 * @author arthurlockman
 */
class Aim: public CommandGroup {
public:	
	Aim();
};

#endif
