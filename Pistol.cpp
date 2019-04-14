#include "Pistol.h"

enum { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };


void Pistol::init(float x, float y)
{

	x_pos = x;
	y_pos = y;
}
void Pistol::move()
{
	y_pos += 2;
}
