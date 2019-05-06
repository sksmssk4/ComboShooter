#include "Entity.h"
#ifndef SUMMONITEM3_H
#define SUMMONITEM3_H

class SummonItem3 :public Entity {

public:
	bool jump = false;
	bool Appear = false;
	bool Reduction = false;
	void init(float x, float y);
	void Update(float time);
	void Jump();
};

#endif