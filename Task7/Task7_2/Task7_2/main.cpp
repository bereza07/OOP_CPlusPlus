#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <string>
#include <memory>

std::mutex monstersMutex;
std::mutex fightMutex;
std::mutex logMutex;

class Character {
public:
    Character(std::string name, int hp, int atk, int def)
        : name(std::move(name)), hp(hp), atk(atk), def(def) {}

    void takeDamage(int damage) {
        std::lock_guard<std::mutex> lock(dataMutex);
        int actualDamage = damage - def;
        if (actualDamage < 1) actualDamage = 1;
        hp -= actualDamage;
        if (hp < 0) hp = 0;
    }

    bool isAlive() const {
        std::lock_guard<std::mutex> lock(dataMutex);
        return hp > 0;
    }

    void displayInfo() const {
        std::lock_guard<std::mutex> lock(dataMutex);
        std::cout << name << " HP: " << hp << ", ATK: " << atk << ", DEF: " << def << "\n";
    }

    std::string getName() const { return name; }
    int getAttack() const { return atk; }

private:
    std::string name;
    int hp, atk, def;
    mutable std::mutex dataMutex;
};

using Monster = Character;
std::vector<std::shared_ptr<Monster>> monsters;

void generateMonsters() {

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::string monsterName = "Dragon";
        auto monster = std::make_shared<Monster>(monsterName, 50, 15, 5);

        {
            std::lock_guard<std::mutex> lock(monstersMutex);
            monsters.push_back(monster);
        }

        {
            std::lock_guard<std::mutex> logLock(logMutex);
            std::cout << "New monster generated!\n";
        }
    }
}

void fight(std::shared_ptr<Character> hero, std::shared_ptr<Monster> monster) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::lock_guard<std::mutex> lock(fightMutex);
        if (!hero->isAlive() || !monster->isAlive()) break;

        monster->takeDamage(hero->getAttack());
        {
            std::lock_guard<std::mutex> logLock(logMutex);
            std::cout << hero->getName() << " attacks " << monster->getName() << "\n";
            hero->displayInfo();
            monster->displayInfo();
        }

        if (!monster->isAlive()) break;

        hero->takeDamage(monster->getAttack());
        {
            std::lock_guard<std::mutex> logLock(logMutex);
            std::cout << monster->getName() << " attacks " << hero->getName() << "\n";
            hero->displayInfo();
            monster->displayInfo();
        }
    }

    {
        std::lock_guard<std::mutex> logLock(logMutex);
        std::cout << "Fight over: " << (hero->isAlive() ? "Hero wins!" : "Monster wins!") << "\n";
    }
}

int main() {
    auto hero = std::make_shared<Character>("Hero", 100, 20, 10);
    monsters.push_back(std::make_shared<Monster>("Dragon", 80, 25, 8));

    std::thread monsterGenerator(generateMonsters);
    monsterGenerator.detach();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread battle;
    {
        std::lock_guard<std::mutex> lock(monstersMutex);
        if (!monsters.empty()) {
            battle = std::thread(fight, hero, monsters[0]);
        }
    }

    if (battle.joinable())
        battle.join();

    return 0;
}
