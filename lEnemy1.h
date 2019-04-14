
#include "Entity.h"
#ifndef LENEMY1_H
#define LENEMY1_H
#define LENEMY1_NUM 6

class lEnemy1 :public Entity {

public:
	void init(float x, float y);
	void move();
};

#endif