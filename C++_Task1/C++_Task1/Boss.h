#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
private:
	std::string m_special;

public:
	Boss(const std::string& n, float h, const std::string& t,const std::string& special);

	void displayInfo() const override;
};

