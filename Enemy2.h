#include "Entity.h"
#include <time.h>
#ifndef ENEMY2_H
#define ENEMY2_H
#define ENEMY2_NUM 6

class Enemy2 :public Entity {

public:
	void init(float x, float y);
	void move();
	void move2(); // ȸ������
	void movePattern();
	bool miss = false;
};

#endif