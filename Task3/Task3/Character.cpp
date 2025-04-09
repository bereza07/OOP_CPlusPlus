#include "Character.h"

Character::Character(const std::string& name, int hp, int attack, int def)
	:m_name(name),
	m_health(hp),
	m_attack(attack),
	m_defense(def)
{
	std::cout << "Character " << m_name << " created!\n";
}

bool Character::operator==(const Character& other) const
{
	return m_name == other.m_name && m_health == other.m_health;
}


Character::~Character()
{
	std::cout << "Character " << m_name << " destroyed!\n";
}

std::ostream& operator<<(std::ostream& os, const Character& character)
{
	os << "\nCharacter: " << character.m_name << "\nHealth: " << character.m_health
		<< "\nAttack: " << character.m_attack << "\nDefense: " << character.m_defense << std::endl;
	return os;
}
