#pragma once
#include "Monster.h"
class Goblin : public Monster
{
private:
	float m_height;
public:
	Goblin(std::string name, float hp, float att, float def, float height);
	void displayInfo() const override;
};

