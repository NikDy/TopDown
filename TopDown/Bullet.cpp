#include "Bullet.h"
#include <functional>


Bullet::Bullet(std::string textureName = "NoTexture", float xPos = 0, float yPos = 0, float angle = 0, float speed = 0, float lifetime = 0) : Entity(textureName, xPos, yPos)
{
	Bullet::angle = angle;
	Bullet::speed = speed;
	Bullet::lifeTime = lifetime;
}


void Bullet::checkEveryFrame()
{
	Entity::xPos += Bullet::speed * sin(Bullet::angle);
	Entity::yPos += Bullet::speed * cos(Bullet::angle);
	Bullet::lifeTime -= 15;
	if (lifeTime <= 0) Bullet::~Bullet();
}


Bullet::~Bullet()
{
	Entity::~Entity();
}
