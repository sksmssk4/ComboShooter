#include "Entity.h"
#ifndef SCORE_H
#define SCORE_H


class Score:public Entity
{
private:
	int sNum = 0;
public:
	int GetNum(){ return sNum; }
	void SetNum(int num) { sNum = num; }
	void init(float x, float y);
};
#endif
