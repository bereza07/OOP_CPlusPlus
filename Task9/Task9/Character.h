#include "Actor.h"
#include "Inventory.h"
#include <memory> 

class Character : public Actor
{
private:
    int m_level = 1;
    float m_xp = 0.f, m_maxHP, m_xpToLevelUp = 10.f;
    std::unique_ptr<Inventory> m_inv; 
public:
    void heal(float amount);
    void gainXP(float amount);
    void displayInfo() const override;

    Character(std::string n, float hp, float a, float def);

    float getXP() { return m_xp; }
    int getLevel() { return m_level; }

    std::string getInventory() {
        return m_inv ? m_inv->getItems() : "Inventory not valid!\n";
    }

    Inventory* getInventoryRef() { return m_inv.get(); }
};
