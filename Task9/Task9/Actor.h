#pragma once
#include <iostream>
class Actor
{
protected:
	std::string m_name;
	float m_hp, m_attack, m_def;

public:
	Actor(std::string name, float hp, float att, float def);
	void attack(Actor* target);
	virtual void displayInfo() const;
	void TakeDamage(float amount);

	std::string getName() { return m_name;}
	float getHealth() { return m_hp; }
	float getAttack() { return m_attack; }
	float getDef() { return m_def; }

};

