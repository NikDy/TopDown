#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:
	Enemy(sf::Texture, float, float, float);
	void runAI(Entity);
	bool deleted;
	~Enemy();
private:
	void moveForward();
	void watchTarget(Entity);
	float speed = 1.0;
	float angle;
};

