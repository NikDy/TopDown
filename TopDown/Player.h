#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <math.h>
class Player :
	public Entity
{
public:
	Player(sf::Texture, float , float , float);
	~Player();
	void goSide(int);
	void watchTarget(float, float);
	Bullet* shootBullet(sf::Texture);
	bool deleted;
private:
	float angle;
};

