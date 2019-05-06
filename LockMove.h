#include "Entity.h"
#ifndef LOCKMOVE_H
#define LOCKMOVE_H

class LockMove :public Entity {

public:
	void init(float x, float y);
	void move();

};

#endif