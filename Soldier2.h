#include "Entity.h"
#ifndef SOLDIER2_H
#define SOLDIER2_H

class Soldier2 :public Entity {

public:
	//Soldier ��������
	bool Show = false;
	bool Fire = false;
	void init(float x, float y);

};

#endif 