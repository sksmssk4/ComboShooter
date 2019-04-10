#include "SummonItem2.h"


void SummonItem2::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
	jump = true;
}

void SummonItem2::Update(float time)
{
	velocityY += gravity * time;
	x_pos += velocityX * time;
	y_pos += velocityY * time;
}

void SummonItem2::Jump()
{
	if (jump)
	{
		velocityX = -2.0;
		velocityY = -13.0;
		jump = false;
	}

}

