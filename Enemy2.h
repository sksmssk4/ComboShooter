#ifndef ENEMY2_H
#define ENEMY2_H
#define ENEMY2_NUM 6

#include "Enemy.h"
#include <time.h>

class Enemy2 :public Enemy {

public:
	//가상함수 선언=(공유하는 부분(중복된)을 한 곳에 관리(재사용))
	virtual void init(float x, float y) override;
	virtual void move() override;
	// 회피패턴
	void move2();
	void movePattern();
	bool miss = false;
};

#endif