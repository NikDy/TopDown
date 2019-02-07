#include "Player.h"
#include "Bullet.h"


Player::Player(std::string textureName = "NoTexture", float xPos = 0, float yPos = 0, float angle = 0) : Entity(textureName, xPos, yPos)
{
	Player::angle = angle;
	Entity::sprite.setRotation(Player::angle);
}


void Player::watchTarget(float x, float y)
{
	Player::angle = atan2f((x - sprite.getPosition().x - 25), (sprite.getPosition().y - 25 - y)) * (180.0 / 3.141592653589793238463);
	Entity::sprite.setRotation(Player::angle);
}


void Player::goSide(int side)
{
	if (side == 0) Entity::sprite.move(10, 0);
	if (side == 1) Entity::sprite.move(2.5, 2.5);
	if (side == 2) Entity::sprite.move(0, 10);
	if (side == 3) Entity::sprite.move(-2.5, 2.5);
	if (side == 4) Entity::sprite.move(-10, 0);
	if (side == 5) Entity::sprite.move(-2.5, -2.5);
	if (side == 6) Entity::sprite.move(0, -10);
	if (side == 7) Entity::sprite.move(2.5, -2.5);
}

void Player::shootBullet()
{
	Bullet::Bullet("Bullet.png", Entity::xPos, Entity::yPos, Player::angle, 4, 15000);
}

Player::~Player()
{
}
