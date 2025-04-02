#include "Character1.h"
#include "Character.h"

Character1::Character1(const std::string& n, int h, int a, int d)
	: Entity1(n, h, a, d)
{
}

void Character1::attack(Entity1& target)
{
	float damageReduction = 1 - (1 / (1 + m_k * target.getDefence()));
	float damage = m_attack - m_attack * damageReduction;
	if (damage > 0) {
		if (rand() % 100 < m_critChance) {
			damage *= 2;
			std::cout << "Critical strike" <<std::endl;
		}
		target.TakeDamage(damage);
		std::cout << m_name << " attacks " << target.getName() << " for " << damage << " damage!\n";
	}
	else {
		std::cout << m_name << " attacks " << target.getName() << ", but it has no damage!\n";
	}
}

void Character1::heal(float amount)
{
	m_health = clamp(m_health + amount, 0.f, 100.f);
	std::cout << "Character healed for: " << amount << std::endl;
}

void Character1::displayInfo() const
{
	std::cout << "Character: " << m_name << "\nHealth: " << m_health
		<< "\nAttack: " << m_attack << "\nDefense: " << m_defense << std::endl;
}
