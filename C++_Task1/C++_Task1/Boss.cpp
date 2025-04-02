#include "Boss.h"


Boss::Boss(const std::string& n, float h, const std::string& t, const std::string& special)
	:Enemy(n, h, t),
	m_special(special)
{
}

void Boss::displayInfo() const
{
	Enemy::displayInfo();
	std::cout << "Special ability: " << m_special << std::endl;
}
