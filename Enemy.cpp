#include "Enemy.h"


bool ground = false;

void Enemy::init(float x, float y)
{
	x_pos = x;
	y_pos = y;

}

void Enemy::move()
{
	y_pos -= 1;
}

void Enemy::Update(float time)
{
	x_pos += velocityX * time;
	y_pos += velocityY * time;
	velocityY += gravity * time;
	if (y_pos >= 600)
	{
		y_pos = 600;
		velocityY = 0.0f;
		ground = true;
	}
}

void Enemy::OnJumpKeyPressed()
{
	if (ground)
	{
		velocityY -= 700.0f;
		ground = false;
	}
}

void Enemy::OnJumpKeyReleased()
{
	if (velocityY < -6.0f)
		velocityY = -6.0f;
}

