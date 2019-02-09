#include <string>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#pragma once
class Entity
{
public:
	Entity(std::string, float, float);
	sf::Sprite sprite;
	~Entity();
private:
	void CreateSprite();
	std::string textureName;
	sf::Texture texture;
protected:
	void updatePosition();
	float xPos;
	float yPos;
};

