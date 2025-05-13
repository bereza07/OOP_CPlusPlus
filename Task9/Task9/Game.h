#pragma once
#include "Character.h"
#include "Monster.h"
#include <memory>
#include "Logger.h"
class Game
{
private:
	std::unique_ptr<Character> m_player;
	Logger<std::string> log;

public:
	Game();
	void start();
	void battle(Monster& enemy);
	void saveGame(const std::string& filename) const;
	void loadGame(const std::string& filename);

	std::unique_ptr<Monster> generateRandomMonster();

};

