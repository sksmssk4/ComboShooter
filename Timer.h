#include "Entity.h"
#include <time.h>
#ifndef TIMER_H
#define TIMER_H

class Timer :public Entity {

public:

	void move();
	void init(float x, float y);

};

#endif 

