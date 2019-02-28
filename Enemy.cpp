#include "Enemy.h"


bool jump = false;
void Enemy::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
	jump = true;
}

void Enemy::Update(float time)
{
	
	velocityY += gravity * time;
	x_pos += velocityX * time;
	y_pos += velocityY * time;
	
}

void Enemy::Jump()
{
	if (jump)
	{
		velocityX = -1.0;
		velocityY = -12.0;
		jump = false;
	}
	
}

