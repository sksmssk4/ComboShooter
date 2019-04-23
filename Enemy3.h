#ifndef ENEMY3_H
#define ENEMY3_H

#include "Enemy.h"

class Enemy3 :public Enemy {

public:
	//가상함수 선언=(공유하는 부분(중복된)을 한 곳에 관리(재사용))
	virtual void init(float x, float y) override;
	virtual void move() override;
	bool attack = false;
	bool blind = false;
};

#endif