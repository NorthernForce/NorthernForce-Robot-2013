#ifndef PREPARE_SHOOTER_H
#define PREPARE_SHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Arthur Lockman
 */
class PrepareShooter: public CommandGroup {
public:
	PrepareShooter(float speed, float angle);
};

#endif
