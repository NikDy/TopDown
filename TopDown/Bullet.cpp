#include "Bullet.h"
#include <functional>


Bullet::Bullet(sf::Texture texture, float xPos = 0, float yPos = 0, float angle = 0, float speed = 0, float lifetime = 0) : Entity(texture, xPos, yPos)
{
	this->angle = angle;
	this->speed = speed;
	this->lifeTime = lifetime;
	this->deleted = false;
}


Bullet& Bullet::checkEveryFrame()
{
	Entity::xPos += Bullet::speed * sin((Bullet::angle * 3.141592653589793238463) / 180.0);
	Entity::yPos += Bullet::speed * -cos((Bullet::angle * 3.141592653589793238463) / 180.0);
	Entity::updatePosition();
	this->lifeTime -= 15;
	if (this->lifeTime <= 0) this->deleted = true;
	return *this;
}


Bullet::~Bullet()
{
}
