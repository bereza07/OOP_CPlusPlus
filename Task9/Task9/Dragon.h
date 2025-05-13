#pragma once
#include "Monster.h"
class Dragon : public Monster
{
private:
	float m_firePower;
public:
	Dragon(std::string n, float hp, float a, float d, float fP);
	void displayInfo() const override;
};

