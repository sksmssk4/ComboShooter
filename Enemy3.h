#include "Entity.h"
#ifndef ENEMY3_H
#define ENEMY3_H

class Enemy3 :public Entity {

public:
	void init(float x, float y);
	void move();
	bool attack = false;
};

#endif