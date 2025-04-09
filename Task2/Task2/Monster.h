#pragma once
#include <iostream>
class Monster
{
private:
	std::string m_name;
	int m_health, m_attack, m_defense;
public:
	Monster(const std::string& name, int hp, int attack, int def);
	void DisplayInfo() const;
	~Monster();
};

