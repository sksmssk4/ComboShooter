#include "BulletMove.h"

void BulletMove::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
	show = true;
}
void BulletMove::move()
{
	y_pos += 10.0;
	if (y_pos >= 601)
		show = false;
}
