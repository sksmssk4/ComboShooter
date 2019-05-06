#include "lEnemy3.h"

void lEnemy3::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void lEnemy3::move()
{
	y_pos -= 2;
	x_pos += 5;
}