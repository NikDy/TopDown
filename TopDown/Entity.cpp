#include "Entity.h"


Entity::Entity(sf::Texture texture, float xPos = 0, float yPos = 0)
{
	Entity::texture = texture;
	Entity::xPos = xPos;
	Entity::yPos = yPos;
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
	if(Entity::sprite.getGlobalBounds().intersects(target.sprite.getGlobalBounds())) return true;
	else return false;
}


void Entity::updatePosition()
{
	Entity::sprite.setPosition(Entity::xPos, Entity::yPos);
}


Entity::~Entity()
{
}
