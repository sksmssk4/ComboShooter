#pragma once

#include "Entity.h"
#ifndef BOTTLE_H
#define BOTTLE_H
#define BOTTLE_NUM 10

class Bottle :public Entity {

public:


	bool jump = false;
	bool breaking = false;
	void init(float x, float y);
	void Update(float time);
	void Jump();
	void BottleScale();
};

#endif
