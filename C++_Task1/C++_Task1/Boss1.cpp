#include "Boss1.h"

Boss1::Boss1(const std::string& n, int h, int a, int d)
	:Monster(n, h, a, d)
{
}

void Boss1::attack(Entity1& target)
{
	float damageReduction = 1 - (1 / (1 + m_k * target.getDefence()));
	float damage = m_attack - m_attack * damageReduction;
	if (damage > 0) {
		if (rand() % 100 < m_fireChance) {
			damage += 10;
			std::cout << "Fire attack" << std::endl;
		}
		target.TakeDamage(damage);
		std::cout << m_name << " attacks " << target.getName() << " for " << damage << " damage!\n";
	}
	else {
		std::cout << m_name << " attacks " << target.getName() << ", but it has no damage!\n";
	}
}
