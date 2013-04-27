#ifndef FLICKFRISBEE_H
#define FLICKFRISBEE_H

#include "Commands/CommandGroup.h"
#include "../Library.h"

/**
 *
 *
 * @author arthurlockman
 */
class FlickFrisbee: public CommandGroup {
public:	
	FlickFrisbee(bool ramp, float speed = kPyramidBackSpeed, float angle = kPyramidBackAngle);
};

#endif
