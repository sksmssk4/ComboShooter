#ifndef LENEMY1_H
#define LENEMY1_H

#include "Enemy.h"

class lEnemy1 :public Enemy {

public:
	//�����Լ� ����=(�����ϴ� �κ�(�ߺ���)�� �� ���� ����(����))
	virtual void init(float x, float y) override;
	virtual void move() override;
};

#endif