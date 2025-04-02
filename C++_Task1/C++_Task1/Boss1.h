#pragma once
#include "Monster.h"
class Boss1 : public Monster
{
private:
	float m_fireChance = 35.f;
public:
	Boss1(const std::string& n, int h, int a, int d);

	void attack(Entity1& target) override;
};

