#pragma once

#include "Entity.h"
#ifndef PISTOL_H
#define PISTOL_H

class Pistol :public Entity {

public:
	//P(pistol)아이템 먹음 유무
	bool pCheck = false;
	//Pistol 등장 유무
	bool pShow = true;
	void init(float x, float y);
	void move();

};

#endif 

