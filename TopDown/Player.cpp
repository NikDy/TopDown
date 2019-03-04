#include "Player.h"

Player::Player(sf::Texture texture, float xPos = 0, float yPos = 0, float angle = 0) : Entity(texture, xPos, yPos)
{
	Player::angle = angle;
	Entity::sprite.setOrigin(Entity::sprite.getTextureRect().height / 2, Entity::sprite.getTextureRect().width / 2);
	Entity::sprite.setRotation(Player::angle);
	Player::deleted = false;
}


void Player::watchTarget(float x, float y)
{
	Player::angle = atan2f((x - sprite.getPosition().x), (sprite.getPosition().y - y)) * (180.0 / 3.141592653589793238463);
	Entity::sprite.setRotation(Player::angle);
}


void Player::goSide(int side)
{
	if (side == 0)	 Entity::xPos += 5;
	if (side == 1) { Entity::xPos += 1.5; Entity::yPos += 1.5;}
	if (side == 2)   Entity::yPos += 5;
	if (side == 3) { Entity::xPos -= 1.5; Entity::yPos += 1.5; }
	if (side == 4)   Entity::xPos -= 5;
	if (side == 5) { Entity::xPos -= 1.5; Entity::yPos -= 1.5; }
	if (side == 6)   Entity::yPos -= 5;
	if (side == 7) { Entity::xPos += 1.5; Entity::yPos -= 1.5; }
	Entity::updatePosition();
}

Bullet* Player::shootBullet(sf::Texture texture)
{
	Bullet* bullet = new Bullet(texture, this->xPos, this->yPos, this->angle, 25, 350);
	return bullet;
}

Player::~Player()
{
}
