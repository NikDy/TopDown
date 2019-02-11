#include "Enemy.h"



Enemy::Enemy(std::string textureName = "NoTexture", float xPos = 0, float yPos = 0, float angle = 0) : Entity(textureName, xPos, yPos)
{

}


void Enemy::watchTarget(Entity target)
{
	Enemy::angle = atan2f((target.xPos - sprite.getPosition().x - 25), (sprite.getPosition().y - 25 - target.yPos)) * (180.0 / 3.141592653589793238463);
	Entity::sprite.setRotation(Enemy::angle);
}

Enemy::~Enemy()
{
}
