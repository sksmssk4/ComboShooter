#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy :public Entity {
public:
	//가상함수 선언
	virtual void init(float x, float y) {};
	virtual void move() {};
};

#endif