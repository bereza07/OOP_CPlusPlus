#include "Entity1.h"
#include "Character.h"

Entity1::Entity1(const std::string& n, float h, float a, float d)
	:m_name(n),
	m_health(h),
	m_attack(a),
	m_defense(d)
{

}

void Entity1::attack(Entity1& target)
{
	float damageReduction = 1 - (1 / (1 + m_k * target.m_defense));
	float damage = m_attack - m_attack * damageReduction;
	if (damage > 0) {
		m_health = clamp(m_health - damage, 0.f, 100.f);
		std::cout << m_name << " attacks " << target.m_name << " for " << damage << " damage!\n";
	}
	else {
		std::cout << m_name << " attacks " << target.m_name << ", but it has no effect!\n";
	}
}

void Entity1::displayInfo() const
{
	std::cout << "Name: " << m_name << "\nHealth: " << m_health
		<< "\nAttack: " << m_attack << "\nDefense: " << m_defense << std::endl;

}

float Entity1::getDefence() const
{
	return m_defense;
}

const std::string& Entity1::getName() const
{
	return m_name;
}

void Entity1::TakeDamage(float amount)
{
	m_health = clamp(m_health - amount, 0.f, 100.f);
}

void Entity1::heal(float amount)
{
	std::cout << "Entity heal\n";
}

Entity1::~Entity1()
{
}
