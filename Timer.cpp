#include "Timer.h"


void Timer::init(float x, float y)
{

	x_pos = x;
	y_pos = y;
}

void Timer::move()
{
	clock_t begin;
	begin = clock();
	x_pos = 300-((begin / CLOCKS_PER_SEC)*5);
}