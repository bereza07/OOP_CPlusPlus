#include "Game.h"
#include "Utilities.h"
#include <random>
#include "Goblin.h"
#include "Dragon.h"
#include "Skeleton.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Logger.h"



Game::Game()
    :log("game_log.txt")
{	
	m_player = std::make_unique<Character>("Hero", 150, 25, 10);
}

void Game::start()
{
	std::cout << "Welcome to RPG Game!\n";
    while (true) {
        std::cout << "Choose: \n1. New game\n2. Load Game\n";
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            log.clear();
            m_player->displayInfo();
            auto monster = generateRandomMonster();
            std::cout << monster->getName() << " appeared!\n";
            log.log(monster->getName() + " appeared!");
            battle(*monster);
            break;
        }
        else if (choice == 2) {
            loadGame("save.txt");
            m_player->displayInfo();
            auto monster = generateRandomMonster();
            std::cout << monster->getName() << " appeared!\n";
            log.log(monster->getName() + " appeared!");
            battle(*monster);
            break;
        }
        else {
            std::cout << "Not correct input!\n";
        }
    }
}

void Game::battle(Monster& enemy)
{
    while (m_player->getHealth() > 0 && enemy.getHealth() > 0) {
        std::cout << "Choose action:\n";
        printColor("1. Heal", ConsoleColor::Green);
        printColor("2. Attack", ConsoleColor::Red);
        int choice;
        std::cout << "Your choice: ";

        std::cin >> choice;
        try {
            if (choice == 1) {
                m_player->heal(25);
                log.log(m_player->getName() + " heals for: " + std::to_string(25) + " hp");
                enemy.attack(m_player.get());
                log.log(enemy.getName() + " attacks " + m_player->getName());

            }
            else if (choice == 2) {
                m_player->attack(&enemy);
                log.log(m_player->getName() + " attacks " + enemy.getName());
                if (enemy.getHealth() <= 0) {
                    printColor(enemy.getName() + " defeated!\n", ConsoleColor::Green);
                    log.log(m_player->getName() + " defeat " + enemy.getName());
                    m_player->gainXP(50.f);
                    log.log(m_player->getName() + " gain " + std::to_string(50) + " xp");
                    m_player->getInventoryRef()->addItem("gold");
                    log.log(m_player->getName() + " get's gold");
                    break;
                }
                enemy.attack(m_player.get());
                log.log(enemy.getName() + " attacks " + m_player->getName());
            }
            else {
                std::cout << "Invalid choice!\n";
            }

            if (m_player->getHealth() <= 0) {
                printColor("You died! Game over!\n", ConsoleColor::Red);
                log.log(m_player->getName() + " died!");
                break;
            }
        }
        catch (const std::exception& e){
            std::cerr << "Error during battle: " << e.what() << "\n";

        }

        if (m_player) m_player->displayInfo();
        if (&enemy) enemy.displayInfo();
    }
}

void Game::saveGame(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file) throw std::runtime_error("Failed to open file for saving!");
    file << m_player->getName() << "\n"
        << m_player->getHealth() << "\n"
        << m_player->getAttack() << "\n"
        << m_player->getDef() << "\n"
        << m_player->getXP()<< "\n"
        << m_player->getLevel() << "\n"
        << m_player->getInventory();

    std::cout << "Game saved!\n";
}

void Game::loadGame(const std::string& filename)
{
    std::fstream file(filename);
    if (!file) throw std::runtime_error("Failed to open file for loading!");
    
    std::string name, inv;
    float hp, att, def, xp, level;
    std::getline(file, name);
    file >> hp >>att >> def>> xp >>level;
    file.ignore();
    std::getline(file, inv);
    m_player = std::make_unique<Character>(name, hp, att, def);
    if (level > 0) {
        m_player->gainXP(xp + level * 10);
    }
    else {
        m_player->gainXP(xp);
    }
    std::stringstream ss(inv);
    std::string item;
    while (std::getline(ss, item, ',')) {
        m_player->getInventoryRef()->addItem(item);
    }
    std::cout << "File successfully loaded!\n";

}

std::unique_ptr<Monster> Game::generateRandomMonster()
{

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);

    switch (dist(gen)) {
    case 0:
        return std::make_unique<Goblin>("Goblin", 50.f, 10.f, 5.f, 5.5f);
    case 1:
        return std::make_unique<Skeleton>("Skeleton", 30.f, 20.f, 5.f, 10.f);
    case 2:
        return std::make_unique<Dragon>("Dragon", 100.f, 30.f, 20.f, 10.f);
    default:
        return std::make_unique<Goblin>("Goblin", 50.f, 10.f, 5.f, 5.5f);
    }
}

