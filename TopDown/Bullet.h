#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
public:
	Bullet(sf::Texture, float, float, float, float, float);
	Bullet& checkEveryFrame();
	~Bullet();
	bool deleted;
private:
	float speed;
	float angle;
	float lifeTime;
};

