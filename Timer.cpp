#include "Timer.h"


void Timer::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}
void Timer::move()
{
	x_pos -= 0.2;
}