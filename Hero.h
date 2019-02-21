#pragma once

#include "Entity.h"
#ifndef HERO_H
#define HERO_H

class Hero :public Entity {

public:
	void fire();
	void super_fire();
	void move(int i);
	void init(float x, float y);

};

#endif 

