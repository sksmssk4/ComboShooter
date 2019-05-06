#include "Entity.h"
#ifndef BULLETMOVE_H
#define BULLETMOVE_H

class BulletMove :public Entity {

public:
	void init(float x, float y);
	void move();
	bool show = false;
};

#endif