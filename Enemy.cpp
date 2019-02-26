#include "Enemy.h"


bool ground = false;
void Enemy::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void Enemy::Update(float time)
{
	
	velocityY += gravity * time;
	x_pos += velocityX * time;
	y_pos += velocityY * time;
	if (y_pos > 600)
	{
		y_pos = 600;
		velocityY = 0.0;
		ground = true;
	}
	
}

void Enemy::Jump()
{
	if (ground)
	{
		velocityY = -12.0;
		ground = false;
	}
	
}

