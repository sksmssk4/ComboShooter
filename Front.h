#include "Entity.h"
#ifndef FRONT_H
#define FRONT_H
#define FRONT_NUM 10

class Front :public Entity
{
public:
	void init(float x, float y);
	void move();
	void shake();
	bool shaking = false;
};
#endif