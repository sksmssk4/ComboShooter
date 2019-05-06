#include "Entity.h"
#ifndef BAZOOKA_H
#define BAZOOKA_H

class Bazooka :public Entity {

public:
	bool bShow;
	void init(float x, float y);
	bool show();
	void hide();
	void active();
	bool check_collision(float x, float y);
	bool jump = false;
	void Update(float time);
	void Jump();
	bool bFire = false;

};

#endif
