#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	int m_exp;
public:
	Player(const std::string& n, float h, int exp);
	void displayInfo() const override;
};

