#pragma once

#include "Entity.h"
#ifndef ENEMY_H
#define ENEMY_H

const double PI = 3.14159265;

class Enemy :public Entity {

public:
	float scale = 1.0;


	void init(float x, float y);
	void Update(float time);
	void Jump();

	//virtual void setDegrees(float deg) { angle = deg*((float)PI / 180.0f); }

};

#endif
