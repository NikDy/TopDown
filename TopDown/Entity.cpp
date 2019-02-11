#include "Entity.h"


Entity::Entity(std::string textureName = "NoTexture", float xPos = 0, float yPos = 0)
{
	Entity::textureName = textureName;
	Entity::xPos = xPos;
	Entity::yPos = yPos;
	Entity::texture.loadFromFile(textureName);
	Entity::texture.setSmooth(true);
	Entity::CreateSprite();
}


void Entity::CreateSprite()
{
	Entity::sprite.setTexture(Entity::texture, true);
	Entity::sprite.setPosition(Entity::xPos, Entity::yPos);
}


float Entity::getxPos()
{
	return Entity::xPos;
}


float Entity::getyPos()
{
	return Entity::yPos;
}


void Entity::updatePosition()
{
	Entity::sprite.setPosition(Entity::xPos, Entity::yPos);
}


Entity::~Entity()
{
}
