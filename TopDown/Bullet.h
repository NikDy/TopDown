#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
public:
	Bullet(std::string, float, float, float, float, float);
	void checkEveryFrame();
	~Bullet();
private:
	float speed;
	float angle;
	float lifeTime;
};

