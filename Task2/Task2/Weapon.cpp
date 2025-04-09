#include "Weapon.h"

Weapon::Weapon(const std::string& name, int attack, int weight)
	:m_name(name),
	m_attack(attack),
	m_weight(weight)
{
	std::cout << "Weapon " << m_name << " created!\n";
}

void Weapon::DisplayInfo() const
{
	std::cout << "\nName: " << m_name << "\nAttack: " << m_attack << "\nWeight: " << m_weight << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon" << m_name << " destroyed!\n";
}
