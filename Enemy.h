#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy :public Entity {
public:
	//�����Լ� ����
	virtual void init(float x, float y) {};
	virtual void move() {};
};

#endif