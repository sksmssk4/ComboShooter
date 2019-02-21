#include "Hero.h"

enum { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };
bool sphere_collision_check(float x0, float y0, float size0, float x1, float y1, float size1);

void Hero::init(float x, float y)
{

	x_pos = x;
	y_pos = y;

}

void Hero::move(int i)
{
	switch (i)
	{
	case MOVE_UP:
		y_pos -= 8;
		break;

	case MOVE_DOWN:
		y_pos += 8;
		break;


	case MOVE_LEFT:
		x_pos -= 8;
		break;


	case MOVE_RIGHT:
		x_pos += 8;
		break;

	}

}