#include "Weapon.h"
#include "Character.h"
#include <iostream>


int main() {
	Character hero("Hero", 100, 25, 15);
	Character hero1("Hero", 100, 25, 15);
	Character warrior("Warrior", 60, 10, 10);
	Weapon Excalibur("Excalibur", 150);
	Weapon bow("Great bow", 25);

	std::cout << hero;
	std::cout << warrior;
	std::cout << Excalibur;

	if (hero == hero1) {
		std::cout << "\nHero and hero1 are the same!\n";
	}
	if (!(hero == warrior)) {
		std::cout << "Hero and warrior are not the same!\n";
	}

	std::cout << Excalibur + bow;

	if (Excalibur > bow) {
		std::cout << "Excalibur stronger than great bow\n";
	}

	return 0;
}