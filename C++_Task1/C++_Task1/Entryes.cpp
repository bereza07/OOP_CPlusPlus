#include "Character.h"

void Task1_1() {
	Character hero("Hero", 100, 20, 40);
	Character enemy("Wolf", 100, 15, 60);
	hero.displayInfo();
	enemy.displayInfo();
	std::cout << std::endl;
	hero.attackEnemy(enemy);
	enemy.displayInfo();
	std::cout << std::endl;
	enemy.attackEnemy(hero);
	hero.displayInfo();
	std::cout << std::endl;
	hero.heal(50);
	hero.displayInfo();
	std::cout << std::endl;
	enemy.takeDamage(900);
	enemy.displayInfo();
}