#include "Inventory.h"
int main() {
	Inventory player;

	player.AddItem("Excalibur");
	player.AddItem("Bow");
	player.AddItem("Dagger");

	player.DisplayInventory();

	return 0;
}