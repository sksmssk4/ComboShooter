#ifndef ENEMY2_H
#define ENEMY2_H
#define ENEMY2_NUM 6

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
};

#endif