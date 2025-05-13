#include "Actor.h"

Actor::Actor(std::string name, float hp, float att, float def)
	:m_name(name),
	m_hp(hp),
	m_attack(att),
	m_def(def)
{
}

void Actor::attack(Actor* target)
{
	if (target) {
		if (target->m_hp > 0) {
			target->TakeDamage(m_attack);
		}
		else {
			throw std::runtime_error(m_name + " no health left");
		}
		
	}
}

void Actor::displayInfo() const
{
	std::cout << m_name << ":\nHP: " << m_hp << "\nATT: " << m_attack << "\nDEF: "<< m_def<< '\n';
}

void Actor::TakeDamage(float amount)
{
	float totalDamage = amount - m_def;
	std::cout << "Total damage: " << totalDamage<<"\n";
	if (m_hp - totalDamage < 0) {
		m_hp = 0;
	}
	else {
		m_hp -= totalDamage;
	}
}
