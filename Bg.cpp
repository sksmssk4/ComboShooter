#include "Bg.h"


void Bg::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void Bg::move()
{
	y_pos -= 5.0f;
	if (y_pos <= -640) y_pos = 640;
}

void Bg::shake()
{
	if (x_pos == 0)
		x_pos += 10;
	else if (x_pos == 10)
		x_pos -= 10;
	
}
