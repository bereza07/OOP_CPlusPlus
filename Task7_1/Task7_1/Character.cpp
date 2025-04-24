#include "Character.h"

Character::Character(std::string name, int hp, int lev):
	m_name(name),
	m_health(hp),
	m_level(lev)
{
}

int Character::getHealth() const
{
	return m_health;
}

int Character::getLevel() const
{
	return m_level;
}

std::string Character::getName() const
{
	return m_name;
}

void Character::displayInfo() const
{
	std::cout << "Name: " << m_name << "\nHP: " << m_health
		<< "\nLevel: "<<m_level<< std::endl;
}
