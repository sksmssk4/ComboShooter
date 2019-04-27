#include "Entity.h"
#ifndef BG_H
#define BG_H
#define BG_NUM 10

class Bg :public Entity
{
public:
	void init(float x, float y);
	void move();
	void shake();
	bool shaking = false;
};
#endif