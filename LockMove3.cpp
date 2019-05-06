#include "LockMove3.h"

void LockMove3::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}
void LockMove3::move()
{
	y_pos += 0.15;
}