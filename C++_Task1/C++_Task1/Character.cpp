#include "Character.h"



Character::Character(const std::string& n, float h, float a, float d)
	:m_name(n),
	m_health(h),
	m_attack(a),
	m_defense(d)
{
	
}

int Character::getHealth() const
{
	return m_health;
}

void Character::displayInfo() const
{
	std::cout << "Name: " << m_name << "\nHealth: " << m_health
		<< "\nAttack: " << m_attack << "\nDefense: " << m_defense << std::endl;
}

void Character::attackEnemy(Character& enemy)
{
	float damageReduction = 1 - (1 / (1 + m_k * enemy.m_defense));
	float damage = m_attack - m_attack * damageReduction;
	if (damage > 0){
		enemy.m_health -= damage;
		std::cout << m_name << " attacks " << enemy.m_name << " for " << damage << " damage" << std::endl;
	}
	else {
		std::cout << m_name << " attacks " << enemy.m_name << ", but it has no effect!" << std::endl;
	}
}

void Character::heal(float amount)
{
	m_health = clamp(m_health+amount, 0.f, 100.f);
	std::cout << m_name << " healed for " << amount << ", now his health: " << m_health << std::endl;
}

void Character::takeDamage(float amount)
{
	float damage = amount - amount * (1 - (1 / (1 + m_k * m_defense)));
	m_health = clamp(m_health - damage, 0.f, 100.0f);
	std::cout << m_name << " get hit for " << damage << " damage. Current health: " << m_health << std::endl;
}
