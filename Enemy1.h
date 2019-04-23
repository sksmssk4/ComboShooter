#ifndef ENEMY1_H
#define ENEMY1_H
#define ENEMY1_NUM 6

#include "Enemy.h"

class Enemy1 :public Enemy {

public:
	//가상함수 선언=(공유하는 부분(중복된)을 한 곳에 관리(재사용))
	virtual void init(float x, float y) override;
	virtual void move() override;
};

#endif
