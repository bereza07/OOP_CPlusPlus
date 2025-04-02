#include "Entity.h"

Entity::Entity(const std::string& n, float h)
	: m_name(n), m_health(h)
{
}

void Entity::displayInfo() const
{
	std::cout << "Name: " << m_name << "\nHealth: " << m_health << std::endl;
}

Entity::~Entity()
{
}
