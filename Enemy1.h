#ifndef ENEMY1_H
#define ENEMY1_H

#include "Enemy.h"

class Enemy1 :public Enemy {

public:
	//�����Լ� ����=(�����ϴ� �κ�(�ߺ���)�� �� ���� ����(����))
	virtual void init(float x, float y) override;
	virtual void move() override;
};

#endif
