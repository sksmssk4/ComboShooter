#include "SummonItem.h"


void SummonItem::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void SummonItem::Update(float time)
{
	velocityY += gravity * time;
	x_pos += velocityX * time;
	y_pos += velocityY * time;

}

void SummonItem::Jump()
{
	if (jump)
	{
		velocityX = -2.0;
		velocityY = -11.0;
		jump = false;
	}
	if (y_pos > 576)
		jump = true;
}

