#pragma once
#include "Entity1.h"
class Character1: public Entity1
{
private:
	float m_critChance = 20.f;
public:
	Character1(const std::string& n, int h, int a, int d);

	void attack(Entity1& target) override;
	
	void heal(float amount) override;

	void displayInfo() const override;
};

