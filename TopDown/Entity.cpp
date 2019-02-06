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


Entity::~Entity()
{
}
