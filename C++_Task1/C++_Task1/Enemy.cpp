#include "Enemy.h"

Enemy::Enemy(const std::string& n, float h, const std::string& t)
	:Entity(n, h),
	m_type(t)
{
}

void Enemy::displayInfo() const
{
	Entity::displayInfo();
	std::cout << "Type: " << m_type << std::endl;
}
