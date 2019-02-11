#include "Enemy.h"



Enemy::Enemy(std::string textureName = "NoTexture", float xPos = 0, float yPos = 0, float angle = 0) : Entity(textureName, xPos, yPos)
{
	Entity::sprite.setOrigin(Entity::sprite.getTextureRect().height / 2, Entity::sprite.getTextureRect().width / 2);
	Entity::sprite.setColor(sf::Color(0, 100, 0));
}


void Enemy::runAI(Entity target)
{
	Enemy::watchTarget(target);
	Enemy::moveForward();
}


void Enemy::moveForward()
{
	Entity::xPos += Enemy::speed * sin((Enemy::angle * 3.141592653589793238463) / 180.0);
	Entity::yPos += Enemy::speed * -cos((Enemy::angle * 3.141592653589793238463) / 180.0);
	Entity::updatePosition();
}


void Enemy::watchTarget(Entity target)
{
	Enemy::angle = atan2f((target.getxPos() - sprite.getPosition().x - 25), (sprite.getPosition().y - 25 - target.getyPos())) * (180.0 / 3.141592653589793238463);
	Entity::sprite.setRotation(Enemy::angle);
}


Enemy::~Enemy()
{
}
