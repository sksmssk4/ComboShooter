#include "Enemy3.h"

void Enemy3::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void Enemy3::move()
{
	y_pos -= 2;
	x_pos -= 8;

}