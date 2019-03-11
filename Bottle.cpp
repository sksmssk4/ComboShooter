#include "Bottle.h"


void Bottle::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
	jump = true;
}

void Bottle::Update(float time)
{
	
	velocityY += gravity * time;
	x_pos += velocityX * time;
	y_pos += velocityY * time;
	
}

void Bottle::Jump()
{
	if (jump)
	{
		velocityX = -1.0;
		velocityY = -12.0;
		jump = false;
	}
	
}

