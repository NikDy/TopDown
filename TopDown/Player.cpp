#include "Player.h"


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
	if (side == 0)	 Entity::xPos += 10;
	if (side == 1) { Entity::xPos += 2.5; Entity::yPos += 2.5;}
	if (side == 2)   Entity::yPos += 10;
	if (side == 3) { Entity::xPos -= 2.5; Entity::yPos += 2.5; }
	if (side == 4)   Entity::xPos -= 10;
	if (side == 5) { Entity::xPos -= 2.5; Entity::yPos -= 2.5; }
	if (side == 6)   Entity::yPos -= 10;
	if (side == 7) { Entity::xPos += 2.5; Entity::yPos -= 2.5; }
	Entity::updatePosition();
}

Bullet Player::shootBullet()
{
	Bullet bullet = Bullet::Bullet("D:/SFML Project/TopDown/x64/Debug/Bullet.png", this->xPos, this->yPos, this->angle, 25, 350);
	return bullet;
	//return Bullet::Bullet("D:/SFML Project/TopDown/x64/Debug/Bullet.png", this->xPos, this->yPos, this->angle, 25, 350);
}

Player::~Player()
{
}
