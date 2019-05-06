#include "Front.h"


void Front::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void Front::move()
{
	y_pos -= 7.0f;
	if (y_pos <= -720) y_pos = 720;
}

void Front::shake()
{
	if (x_pos == 0)
		x_pos += 10;
	else if (x_pos == 10)
		x_pos -= 10;

}
