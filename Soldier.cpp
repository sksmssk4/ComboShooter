#include "Soldier.h"

void Soldier::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}
void Soldier::move()
{
	if (!Change)
		x_pos += 6;
	else if (Change)
		x_pos -= 6;
	
}
void Soldier::change()
{
	if (x_pos >= 300)
		Change = true;
	else if (x_pos == 1)
		Change = false;
}
