#ifndef ENEMY2_H
#define ENEMY2_H

#include "Enemy.h"
#include <time.h>

class Enemy2 :public Enemy {

public:
	//�����Լ� ����=(�����ϴ� �κ�(�ߺ���)�� �� ���� ����(����))
	virtual void init(float x, float y) override;
	virtual void move() override;
	// ȸ������
	void move2();
	void movePattern();
	bool miss = false;
	bool appear = false;
};

#endif