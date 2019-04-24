#include "Bg.h"


void Bg::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
	shaking = true;
}

void Bg::shake()
{
	if (shaking)
	{
		x_pos += 10;
		if (x_pos < -20)
			x_pos -= 10;
		shaking = false;
	}
	
}
