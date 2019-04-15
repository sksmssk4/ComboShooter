#include "Enemy1.h"


void Enemy1::init(float x, float y)
{
	x_pos = x;
	y_pos = y;	
}

void Enemy1::move()
{
	y_pos -= 2;
	x_pos -= 6;
}

