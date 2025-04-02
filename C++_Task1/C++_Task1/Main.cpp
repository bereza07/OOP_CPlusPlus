#include "Character.h"

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

#include "Character1.h"
#include "Monster.h"
#include "Entity1.h"
#include "Boss1.h"

#include <iostream>

void Task1_1();
void Task1_2();
void Task1_3();





int main() {
	Task1_3();
	return 0;
}






void Task1_1() {
	//Дебаг 1_1 Практической
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


void Task1_2() {
	Player hero("Hero", 120, 10);
	Enemy wolf("Small Wolf", 160, "Wolf");
	Boss bossWolf("The Proud Wolf", 300.f, "Wolf", "Byte");

	hero.displayInfo();
	wolf.displayInfo();
	bossWolf.displayInfo();
}


void Task1_3() {
	srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел
	Character1 hero("Hero", 100, 20, 10);
	Monster goblin("Goblin", 50, 15, 5);
	Boss1 dragon("Dragon", 150, 25, 20);
	Entity1* entities[] = { &hero, &goblin, &dragon };

	for (auto& entity : entities) {
		entity->displayInfo(); // Вывод информации о сущности
	}
	

	hero.attack(goblin);
	goblin.attack(hero);
	dragon.attack(hero);

	std::cout << std::endl;
	hero.displayInfo();
	hero.heal(30.f);
	hero.displayInfo();
}

