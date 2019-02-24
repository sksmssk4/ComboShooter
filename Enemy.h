#pragma once

#include "Entity.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy :public Entity {

public:
	void fire();
	void init(float x, float y);
	void move();

	void Update(float time);
	void OnJumpkeyPressed();
	void OnJumpKeyReleased();

};

#endif
