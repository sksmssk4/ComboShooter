
#include "Entity.h"
#ifndef ITEM_H
#define ITEM_H

class Item :public Entity {

public:
	bool jump = false;
	bool disAppear = true;
	void init(float x, float y);
	void Update(float time);
	void Jump();
};

#endif
