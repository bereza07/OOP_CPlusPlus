#include "Monster.h"

Monster::Monster(const std::string& name, int hp, int attack, int def)
	:m_name(name),
	m_health(hp),
	m_attack(attack),
	m_defense(def)
{
	std::cout << "Monster " << m_name << " created!\n";
}

void Monster::DisplayInfo() const
{
	std::cout << "\nName: " << m_name << "\nHealth: " << m_health
		<< "\nAttack: " << m_attack << "\nDefense: " << m_defense << std::endl;
}

Monster::~Monster()
{
	std::cout << "Monster " << m_name << " destroyed!\n";
}
