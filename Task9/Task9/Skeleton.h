#pragma once
#include "Monster.h"
class Skeleton : public Monster
{
	float m_durability;
public:
	Skeleton(std::string n, float hp, float a, float d, float dur);
	void displayInfo() const override;
};

