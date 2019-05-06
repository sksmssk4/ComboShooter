#include "Back.h"


void Back::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void Back::move()
{
	y_pos -= 4.0f;
	if (y_pos <= -500) y_pos = 500;
}

void Back::shake()
{
	if (x_pos == 0)
		x_pos += 10;
	else if (x_pos == 10)
		x_pos -= 10;

}
