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


bool Entity::checkCollision(Entity target)
{
	if (((xPos - target.getxPos())*(xPos - target.getxPos()) + (yPos - target.getyPos())*(xPos - target.getyPos()))
		<= (sprite.getTextureRect().height / 2 + target.sprite.getTextureRect().height / 2)) return true;
	else return false;
}


void Entity::updatePosition()
{
	Entity::sprite.setPosition(Entity::xPos, Entity::yPos);
}


Entity::~Entity()
{
}
