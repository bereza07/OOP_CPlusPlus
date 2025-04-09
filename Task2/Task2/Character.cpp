#include "Character.h"

Character::Character(const std::string& name, int hp, int attack, int def)
	:m_name(name),
	m_health(hp),
	m_attack(attack),
	m_defense(def)
{
	std::cout << "Character " << m_name << " created!\n";
}

void Character::DisplayInfo() const
{
	std::cout << "\nName: " << m_name << "\nHealth: " << m_health
		<< "\nAttack: " << m_attack << "\nDefense: " << m_defense << std::endl;
}

Character::~Character()
{
	std::cout << "Character " << m_name << " destroyed!\n";
}
