#ifndef ENEMY3_H
#define ENEMY3_H

#include "Enemy.h"

class Enemy3 :public Enemy {

public:
	//�����Լ� ����=(�����ϴ� �κ�(�ߺ���)�� �� ���� ����(����))
	virtual void init(float x, float y) override;
	virtual void move() override;
	bool attack = false;
	bool blind = false;
};

#endif