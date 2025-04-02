#pragma once
#include "Entity.h"

class Enemy : public Entity
{
private:
	std::string m_type;
public:
	Enemy(const std::string& n, float h, const std::string& t);
	void displayInfo() const override;

};

