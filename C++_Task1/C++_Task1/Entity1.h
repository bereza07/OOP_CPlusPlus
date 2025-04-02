#pragma once
#include <iostream>
class Entity1
{
protected:
    std::string m_name;
    float m_health;
    float m_attack;
    float m_defense;
    float m_k = 0.01f;
public:
    Entity1(const std::string& n, float h, float a, float d);

    virtual void attack(Entity1& target);

    virtual void displayInfo() const;

    float getDefence() const;

    const std::string& getName() const;

    void TakeDamage(float amount);
    virtual void heal(float amount);

    virtual ~Entity1();
};

