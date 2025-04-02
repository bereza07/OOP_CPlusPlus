#include "Player.h"

Player::Player(const std::string& n, float h, int exp)
	:Entity(n,h),
	m_exp(exp)
{
}

void Player::displayInfo() const
{
	Entity::displayInfo();
	std::cout << "Experience: " << m_exp << std::endl;
}
