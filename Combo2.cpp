#include "Combo2.h"


void Combo2::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
	shaking = true;
}

void Combo2::shake()
{
	if (shaking)
	{
		x_pos += 15;
		y_pos -= 15;
		if (x_pos < 720)
		{
			x_pos -= 15;
			y_pos += 15;
		}
		shaking = false;
	}

}
