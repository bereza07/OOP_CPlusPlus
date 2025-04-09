#pragma once
#include <iostream>
class Weapon
{
private:
	std::string m_name;
	int m_attack, m_weight;

public:
	Weapon(const std::string& name, int attack, int weight);

	void DisplayInfo() const;

	~Weapon();
};

