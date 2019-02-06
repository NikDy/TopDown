#include <string>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#pragma once
class Entity
{
public:
	Entity(std::string, float, float);
	void GoSide(int);
	sf::Sprite sprite;
	~Entity();
private:
	void CreateSprite();
	std::string textureName;
	float xPos;
	float yPos;
	sf::Texture texture;
};

