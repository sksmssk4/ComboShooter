#include "Entity.h"
#ifndef COMBO2_H
#define COMBO2_H


class Combo2 :public Entity
{
private:
	int cNum = 0;
public:
	int GetNum() { return cNum; }
	void SetNum(int num) { cNum = num; }
	void init(float x, float y);
	void shake();
	bool shaking = false;
};
#endif