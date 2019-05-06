#ifndef ENEMY_H
#define ENEMY_H

#define ENEMY1_NUM 6
#define ENEMY2_NUM 6
#include "Entity.h"

class Enemy :public Entity {
public:
	//가상함수 선언
	virtual void init(float x, float y) {};
	virtual void move() {};
	bool breaking = false;
	bool bBreaking = false;
};

#endif