#include "Entity.h"
#ifndef SOLDIER_H
#define SOLDIER_H

class Soldier :public Entity {

public:
	//Soldier ��������
	bool Show = false;
	bool Change = false;
	bool Fire = false;
	void init(float x, float y);
	void move();
	void change();

};

#endif 

