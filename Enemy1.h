#pragma once

#include "Entity.h"
#ifndef ENEMY1_H
#define ENEMY1_H
#define ENEMY1_NUM 6

class Enemy1 :public Entity {

public:
	void init(float x, float y);
	void move();
};

#endif
