#include "Chest.h"

void Chest::Init() {
	item = RandomNumber(0, 9);
	gold = RandomNumber(50, 100);
	isOpen = false;
	isPotion = RandomNumber(0, 3);
}