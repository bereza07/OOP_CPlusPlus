#include "Character.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

template <typename T>
class GameManager {
private:
    std::vector<T> entities;

public:
    void addEntity(T entity) {
        if (!entity) {
            throw std::invalid_argument("Null entity cannot be added.");
        }
        if (entity->getHealth() <= 0) {
            throw std::invalid_argument("Entity has invalid health.");
        }
        entities.push_back(std::move(entity));
    }

    void displayAll() const {
        for (const auto& entity : entities) {
            entity->displayInfo();
        }
    }

    const std::vector<T>& getEntities() const {
        return entities;
    }
};

void saveToFile(const GameManager<std::unique_ptr<Character>>& manager, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    for (const auto& entity : manager.getEntities()) {
        file << entity->getName() << ' ' << entity->getHealth() << ' ' << entity->getLevel() << '\n';
    }
}

void loadFromFile(GameManager<std::unique_ptr<Character>>& manager, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::string name;
    int health, level;

    while (file >> name >> health >> level) {
        try {
            manager.addEntity(std::make_unique<Character>(name, health, level));
        }
        catch (const std::exception& e) {
            std::cerr << "Failed to load character: " << e.what() << '\n';
        }
    }
}

int main() {
    try {
        GameManager<std::unique_ptr<Character>> manager;

        manager.addEntity(std::make_unique<Character>("NPC", 100, 1));
        manager.addEntity(std::make_unique<Character>("Hero", 130, 2));

        saveToFile(manager, "game_save.txt");

        GameManager<std::unique_ptr<Character>> loadedManager;
        loadFromFile(loadedManager, "game_save.txt");

        loadedManager.displayAll();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
