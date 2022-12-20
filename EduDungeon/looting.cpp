#include "Looting.h"

void LootingScene(Scene& currentScene, Player& myPlayer, Chest Chests[], int whatChest, Map map[][5]) {
	myPlayer.gold += Chests[whatChest].gold;

	cout << " > You open the chest and it contains the following:" << endl << endl << "       > " << Chests[whatChest].gold << " gold!" << endl << "> The Chest contains Gear!" << endl;

	int numberOfGear = RandomNumber(1, 10);
	WhatGear(numberOfGear, myPlayer);

	if (Chests[whatChest].isPotion >= 1) {
		if (myPlayer.potions >= MaxPotions)
			cout << endl << "              > You already have max potions!";
		else {
			myPlayer.potions++;
			cout << endl << "              > You now have " << myPlayer.potions << '/' << MaxPotions << " potions!";
		}
	}

	cout << endl << endl << "_______________________________________" << endl << endl;
	Chests[whatChest].isOpen = true;
	
	map[Chests[whatChest].X][Chests[whatChest].Y].isUsed = false;
	Chests[whatChest].X += 10;
	Chests[whatChest].Y += 10;
	currentScene = NAVIGATION;
	system("pause");
	system("cls");
}

void WhatGear(int numberOfGear, Player& myPlayer) {
	switch (numberOfGear)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;

	
	default:
		break;
	}
}