#include "Entity.h"
#ifndef SUMMONITEM2_H
#define SUMMONITEM2_H

class SummonItem2 :public Entity {

public:
	bool jump = false;
	bool Appear = false;
	bool Giantization = false;
	void init(float x, float y);
	void Update(float time);
	void Jump();
};

#endif