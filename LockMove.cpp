#include "LockMove.h"
//�������� �ð�
void LockMove::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}
void LockMove::move()
{
	y_pos += 0.2;
}