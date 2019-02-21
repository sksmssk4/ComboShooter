#pragma once

#include "Entity.h"
#ifndef BULLET_H
#define BULLET_H

class Bullet :public Entity {

public:
	bool bShow;
	void init(float x, float y);
	void move();
	bool show();
	void hide();
	void active();
	bool check_collision(float x, float y);


};

#endif


