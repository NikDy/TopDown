#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player(std::string , float , float , float);
	~Player();
	void GoSide(int);
private:
	float angl;
};

