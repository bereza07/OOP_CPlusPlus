#include "Game.h"

int main() {
	try {
		Game game;
		game.start();
		game.saveGame("save.txt");
	}
	catch(const std::exception &e){
		std::cerr << "Unhandled exception: " << e.what() << '\n';
	}
	return 0;
} 