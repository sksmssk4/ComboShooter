#pragma once

#include "Entity.h"
#ifndef PISTOL_H
#define PISTOL_H

class Pistol :public Entity {

public:
	bool pShow = true;
	void fire();
	void super_fire();
	void move(int i);
	void init(float x, float y);

};

#endif 

