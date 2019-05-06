#include "Entity.h"
#ifndef BACK_H
#define BACK_H
#define BACK_NUM 10

class Back :public Entity
{
public:
	void init(float x, float y);
	void move();
	void shake();
	bool shaking = false;
};
#endif