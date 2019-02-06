#pragma once
#include "Entity.h"
#include <math.h>
class Player :
	public Entity
{
public:
	Player(std::string , float , float , float);
	~Player();
	void GoSide(int);
	void WatchTarget(float, float);
private:
	float angle;
};

