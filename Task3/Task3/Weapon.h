#pragma once
#include <iostream>
class Weapon
{
private:
	std::string m_name;
	int m_damage;

public:
	Weapon(const std::string& name, int damage);

	Weapon operator + (const Weapon& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);

	bool operator > (const Weapon& other) const;
	~Weapon();
};

