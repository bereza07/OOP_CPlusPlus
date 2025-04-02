#pragma once
#include <iostream>

class Entity
{
protected:
	std::string m_name;
	float m_health;

public:
	Entity(const std::string& n, float h);

	virtual void displayInfo() const;

	virtual ~Entity();

};

