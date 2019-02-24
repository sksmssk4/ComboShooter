#include "Enemy.h"

float velocityX, velocityY;
float gravity = 7.5f;

void Enemy::Update(float time)
{
	x_pos += velocityX*time;
	y_pos += velocityY*time;
	velocityY += gravity*time;
}
void Enemy::OnJumpkeyPressed()
{
	velocityY = -12.0f;
}

void Enemy::OnJumpKeyReleased()
{
	if (velocityY < 0.0f)
		velocityY = -6.0f;
}

void Enemy::init(float x, float y)
{

	x_pos = x;
	y_pos = y;

}


void Enemy::move()
{
	y_pos += 0.0f;

}