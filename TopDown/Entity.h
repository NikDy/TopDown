#include <string>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "ResourseLoader.h"
#include <iostream>

#pragma once
class Entity
{
	sf::Texture texture;

public:
	Entity(sf::Texture, float, float);
	bool checkCollision(Entity);
	float getxPos();
	float getyPos();
	sf::Sprite sprite;
	virtual ~Entity();
private:
	void CreateSprite();
protected:
	void updatePosition();
	float xPos;
	float yPos;
};

