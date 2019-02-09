#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <math.h>
class Player :
	public Entity
{
public:
	Player(std::string , float , float , float);
	~Player();
	void goSide(int);
	void watchTarget(float, float);
	Bullet shootBullet();
private:
	float angle;
};

