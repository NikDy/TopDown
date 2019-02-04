#include <string>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#pragma once
class Entity
{
public:
	Entity(std::string, float, float);
	void GoSide(int);
	void CreateSprite();
	~Entity();
private:
	std::string textureName;
	float xPos;
	float yPos;
	sf::Texture texture;
	sf::Sprite sprite;
};

