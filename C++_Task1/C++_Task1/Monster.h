#pragma once
#include "Entity1.h"
class Monster : public Entity1
{
private:
	float m_critChance = 30.f;
public:
	Monster(const std::string& n, int h, int a, int d);
	void attack(Entity1& target) override;
	void displayInfo() const override;
};

