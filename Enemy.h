#pragma once

#include "Entity.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy :public Entity {

public:
	void init(float x, float y);
	void Update(float time);
	void Jump();


};

#endif
