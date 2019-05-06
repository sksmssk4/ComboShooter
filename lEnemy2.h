#ifndef LENEMY2_H
#define LENEMY2_H

#include "Enemy.h"
#include <time.h>

class lEnemy2 :public Enemy {

public:
	//가상함수 선언=(공유하는 부분(중복된)을 한 곳에 관리(재사용))
	virtual void init(float x, float y) override;
	virtual void move() override;
	// 회피패턴
	void move2();
	void movePattern();
	bool miss = false;
	bool appear = false;
};

#endif
