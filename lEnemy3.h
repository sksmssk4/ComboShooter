#ifndef LENEMY3_H
#define LENEMY3_H

#include "Enemy.h"

class lEnemy3 :public Enemy {

public:
	//�����Լ� ����=(�����ϴ� �κ�(�ߺ���)�� �� ���� ����(����))
	virtual void init(float x, float y) override;
	virtual void move() override;
	bool attack = false;
	bool appear = false;
};

#endif
