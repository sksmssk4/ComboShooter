#include "Entity.h"
#ifndef BG_H
#define BG_H

class Bg :public Entity
{
public:
	void init(float x, float y);
	void shake();
	bool shaking = false;
};
#endif