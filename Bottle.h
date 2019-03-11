#pragma once

#include "Entity.h"
#ifndef BOTTLE_H
#define BOTTLE_H

const double PI = 3.14159265;

class Bottle :public Entity {

public:
	float scale = 1.0;

	bool jump = false;
	bool breaking = false;

	void init(float x, float y);
	void Update(float time);
	void Jump();

	//virtual void setDegrees(float deg) { angle = deg*((float)PI / 180.0f); }

};

#endif
