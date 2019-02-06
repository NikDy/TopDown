#include "Player.h"



Player::Player(std::string textureName = "NoTexture", float xPos = 0, float yPos = 0, float angl = 0) : Entity(textureName, xPos, yPos)
{
	Player::angl = angl;
	
}

void Player::GoSide(int side)
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

Player::~Player()
{
}
