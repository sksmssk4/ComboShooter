#pragma once

#ifndef ENTITY_H
#define ENTITY_H

//�⺻ Ŭ���� 
class Entity {

public:
	float x_pos;
	float y_pos;
	int status;
	int HP;
	float velocityX;
	float velocityY = 0.0f;
	float gravity = 0.15f;

};

#endif
