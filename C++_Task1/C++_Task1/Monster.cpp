#include "Monster.h"

Monster::Monster(const std::string& n, int h, int a, int d)
	:Entity1(n, h, a, d)
{
}

void Monster::attack(Entity1& target)
{
	float damageReduction = 1 - (1 / (1 + m_k * target.getDefence()));
	float damage = m_attack - m_attack * damageReduction;
	if (damage > 0) {
		if (rand() % 100 < m_critChance) {
			damage += 10;
			std::cout << "Poison attack" << std::endl;
		}
		target.TakeDamage(damage);
		std::cout << m_name << " attacks " << target.getName() << " for " << damage << " damage!\n";
	}
	else {
		std::cout << m_name << " attacks " << target.getName() << ", but it has no damage!\n";
	}
}

void Monster::displayInfo() const
{
	std::cout << "Monster: " << m_name << "\nHealth: " << m_health
		<< "\nAttack: " << m_attack << "\nDefense: " << m_defense << std::endl;
}
