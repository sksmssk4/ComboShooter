#pragma once

#include "Entity.h"
#ifndef PISTOL_H
#define PISTOL_H

class Pistol :public Entity {

public:
	//P(pistol)������ ���� ����
	bool pCheck = false;
	//Pistol ���� ����
	bool pShow = true;
	void init(float x, float y);
	void move();

};

#endif 

