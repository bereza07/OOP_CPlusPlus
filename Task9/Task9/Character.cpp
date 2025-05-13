#include "Character.h"
#include "Utilities.h"
void Character::heal(float amount)
{
	m_hp = clamp(m_hp+amount, 0.f, m_maxHP);
}

void Character::gainXP(float amount)
{
	if (amount > m_xpToLevelUp - m_xp) {
		m_level += int(amount) / m_xpToLevelUp;
		amount = int(amount) % int(m_xpToLevelUp);
		m_xp = amount;
	}
	else {
		m_xp += amount;
	}
}

void Character::displayInfo() const
{
	printColor(m_name, ConsoleColor::Yellow);
	std::cout << "HP: " << m_hp << "\nATT: " << m_attack << "\nDEF: " << m_def
		<< "\nLevel: " << m_level << "\nXP: " << m_xp << "\nXP to level up: " << m_xpToLevelUp - m_xp << "\n";
}

Character::Character(std::string n, float hp, float a, float def)
	:Actor(n,hp,a,def),
	m_maxHP(hp)
{
	m_inv = std::make_unique<Inventory>();
}


