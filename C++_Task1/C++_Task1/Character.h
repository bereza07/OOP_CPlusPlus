#pragma once
#include <iostream>

template<typename T>
const T& clamp(const T& value, const T& min, const T& max) {
	return (value < min) ? min : (value > max) ? max : value;
}

class Character
{
private:
	std::string m_name;
	float m_health, m_attack, m_defense;
	float m_k = 0.01f; // Коэфф. для силы брони

public:
	Character(const std::string& n, float h, float a, float d);

	int getHealth() const;

	void displayInfo() const;

	void attackEnemy(Character& enemy);

	void heal(float amount);

	void takeDamage(float amount);

};


