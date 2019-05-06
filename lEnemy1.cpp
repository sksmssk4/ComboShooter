#include "lEnemy1.h"


void lEnemy1::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void lEnemy1::move()
{
	y_pos -= 2;
	x_pos += 8;
}

