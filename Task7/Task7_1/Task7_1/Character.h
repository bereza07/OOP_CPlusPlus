#pragma once
#include <iostream>


class Character
{
private:
	std::string m_name;
	int m_health, m_level;

public:
	Character(std::string name, int hp, int lev = 0);

	int getHealth() const;
	int getLevel() const;
	std::string getName() const;
	
	void displayInfo() const;
};

