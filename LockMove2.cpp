#include "LockMove2.h"

void LockMove2::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}
void LockMove2::move()
{
	y_pos += 0.15;
}