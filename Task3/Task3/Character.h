#pragma once
#include <iostream>
class Character
{
private:
	std::string m_name;
	int m_health, m_attack, m_defense;
public:
	Character(const std::string& name, int hp, int attack, int def);

	bool operator == (const Character& other) const;


	friend std::ostream& operator<<(std::ostream& os, const Character& character);

	~Character();
};

