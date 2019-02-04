#include "Entity.h"




Entity::Entity(std::string textureName = "NoTexture", float xPos = 0, float yPos = 0)
{
	Entity::textureName = textureName;
	Entity::xPos = xPos;
	Entity::yPos = yPos;
	Entity::texture.loadFromFile(textureName);
}


void Entity::CreateSprite()
{
	Entity::sprite.setTexture(Entity::texture, true);
	Entity::sprite.setPosition(Entity::xPos, Entity::yPos);
}


void Entity::GoSide(int side)
{
	if (side == 0) Entity::sprite.move(10, 0);
	if (side == 1) Entity::sprite.move(7.07, 7.07);
	if (side == 2) Entity::sprite.move(0, 10);
	if (side == 3) Entity::sprite.move(-7.07, 7.07);
	if (side == 4) Entity::sprite.move(-10, 0);
	if (side == 5) Entity::sprite.move(-7.07, -7.07);
	if (side == 6) Entity::sprite.move(0, -10);
	if (side == 7) Entity::sprite.move(7.07, -7.07);
}


Entity::~Entity()
{
}
