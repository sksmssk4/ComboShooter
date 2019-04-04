
#include "Entity.h"
#ifndef SUMMONITEM_H
#define SUMMONITEM_H

class SummonItem :public Entity {

public:
	bool jump = false;
	bool Appear = false;
	void init(float x, float y);
	void Update(float time);
	void Jump();
};

#endif
