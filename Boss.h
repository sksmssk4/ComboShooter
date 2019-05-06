#include "Entity.h"
#ifndef BOSS_H
#define BOSS_H

class Boss :public Entity {

public:
	bool hit = false;
	bool breaking = false;
	bool Appear = false;
	void init(float x, float y);

};

#endif