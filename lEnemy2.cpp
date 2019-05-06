#include "lEnemy2.h"


void lEnemy2::init(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

void lEnemy2::move()
{
	y_pos -= 2;
	x_pos += 9;

}

void lEnemy2::move2()
{
	x_pos -= 3;
}

void lEnemy2::movePattern()
{
	if (x_pos < 950 || x_pos > 50)
	{
		clock_t begin2;
		begin2 = clock();
		int j = 1000;
		if ((begin2 / j) % 3 == 2)
		{
			miss = true;
		}
		else
			miss = false;
	}
}
