#include "Pistol.h"

enum { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };


void Pistol::init(float x, float y)
{

	x_pos = x;
	y_pos = y;

}

void Pistol::move(int i)
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