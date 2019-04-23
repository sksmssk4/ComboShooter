#include "Entity.h"
#ifndef COMBO_H
#define COMBO_H


class Combo :public Entity
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