#include "Character.h"
#include "Monster.h"
#include "Weapon.h"
#include <iostream>

int main() {
	Character hero("Hero", 100, 10, 10);
	Monster goblin("Goblin", 35, 10, 5);
	Weapon Excalibur("Excalibur", 100, 500);

	hero.DisplayInfo();
	goblin.DisplayInfo();
	Excalibur.DisplayInfo();

	return 0;
}