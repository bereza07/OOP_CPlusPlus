#include "Weapon.h"

Weapon::Weapon(const std::string& name, int damage)
    :m_name(name),
    m_damage(damage)
{
    std::cout << "Weapon " << m_name << " created!\n";
}

Weapon Weapon::operator+(const Weapon& other) const
{
    std::string newName = m_name + " + " + other.m_name;
    int newDamage = m_damage + other.m_damage;
    return Weapon(newName, newDamage);
}

bool Weapon::operator>(const Weapon& other) const
{
    return m_damage > other.m_damage;
}

Weapon::~Weapon()
{
    std::cout << "Weapon " << m_name << " destroyed!\n";
}

std::ostream& operator<<(std::ostream& os, const Weapon& weapon)
{
    os << "\nWeapon name: " << weapon.m_name << std::endl << "Weapon damage: " << weapon.m_damage << std::endl;
    return os;
}
