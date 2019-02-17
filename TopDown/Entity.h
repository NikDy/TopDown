#include <string>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
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
	~Entity();
private:
	void CreateSprite();
protected:
	void updatePosition();
	float xPos;
	float yPos;
};

