#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:
	Enemy(std::string , float, float, float);
	~Enemy();
private:
	float angle;
};

