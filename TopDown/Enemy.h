#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:
	Enemy(std::string , float, float, float);
	void runAI(Entity);
	~Enemy();
private:
	void moveForward();
	void watchTarget(Entity);
	float speed = 0.8;
	float angle;
};

