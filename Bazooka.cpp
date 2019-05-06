#include "Bazooka.h"

bool sphere_collision_check(float x0, float y0, float size0, float x1, float y1, float size1);

bool Bazooka::check_collision(float x, float y)
{
	//충돌 처리 시 
	if (sphere_collision_check(x_pos, y_pos, 32, x, y, 32) == true)
	{
		bShow = false;
		return true;
	}
	else {
		return false;
	}
}

void Bazooka::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}
void Bazooka::Update(float time)
{
	velocityY += gravity * time;
	x_pos += velocityX * time;
	y_pos += velocityY * time;

}

void Bazooka::Jump()
{
	if (jump)
	{
		velocityX = -7.0;
		velocityY = -11.0;
		jump = false;
	}
	if (y_pos >= 490)
		jump = true;
}

bool Bazooka::show()
{
	return bShow;

}

void Bazooka::active()
{
	bShow = true;

}

void Bazooka::hide()
{
	bShow = false;

}