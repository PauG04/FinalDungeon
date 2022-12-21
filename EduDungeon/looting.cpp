#include "Looting.h"

void LootingScene(Scene& currentScene, Player& myPlayer, Chest Chests[], int whatChest, Map map[][5]) {
	myPlayer.gold += Chests[whatChest].gold;

	cout << "- - - - - - CHEST - - - - - -" << endl << endl << " > You open the chest and it contains the following:" << endl << endl << "       > " << Chests[whatChest].gold << " gold!" << endl << "       > The Chest contains Gear!" << endl;

	int usedGear = 0, numberOfGear = RandomNumber(1, 11);
	do {
		numberOfGear = RandomNumber(1, 11);
	} while (numberOfGear == usedGear);
	usedGear = numberOfGear;
	WhatGear(numberOfGear, myPlayer);

	if (Chests[whatChest].isPotion >= 1) {
		cout << endl << "       > The Chest contains a potion!" << endl;
		if (myPlayer.potions >= MaxPotions)
			cout << "              > You already have max potions!";
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
	case 1: //PAU'S COCACOLA
		myPlayer.gold += 85;
		myPlayer.maxMoves += 1;
		myPlayer.maxStamina += 30;
		myPlayer.stamina += 30;
		cout << "              > COCACOLA ESPUMA!!" << endl << "              > PAU's COCACOLA  +85 Gold  +1 Agility  +30 Stamina" << endl;

		break;
	case 2:
		myPlayer.gold += 60;
		myPlayer.maxMoves += 1;
		myPlayer.maxHealth -= 10;
		myPlayer.health -= 10;
		myPlayer.maxStamina += 20;
		myPlayer.stamina += 20;
		cout << "              > You feel comfortable" << endl << "              > AUGUSTUS' CROCS  +60 Gold  +1 Agility  -10 Health  +20 Stamina" << endl;

		break;
	case 3:
		myPlayer.gold += 60;
		myPlayer.maxMoves += 2;
		myPlayer.maxHealth -= 20;
		myPlayer.health -= 20;
		myPlayer.maxStamina += 40;
		myPlayer.stamina += 40;
		cout << "              > FIAUUUUUM!!" << endl << "              > AUGUSTUS’ CROCS (Sport mode)  +60 Gold  +2 Agility  -20 Health  +40 Stamina" << endl;

		break;
	case 4:
		myPlayer.gold += 85;
		myPlayer.maxHealth -= 10;
		myPlayer.health -= 10;
		myPlayer.maxStamina += 30;
		myPlayer.stamina += 30;
		cout << "              > Que es De Chill y que le estas haciendo a mi abuela!?" << endl << "              > VIETNAMITA's COOFFE  +85 Gold  -10 Health  +30 Stamina" << endl;
		break;
	case 5:
		myPlayer.gold += 4000;
		myPlayer.maxHealth += 1;
		myPlayer.health += 1;
		cout << "              > Think Different" << endl << "              > MIVI's iPAD  +4000 Gold" << endl;
		break;
	case 6:
		myPlayer.gold += 350;
		myPlayer.maxHealth += 30;
		myPlayer.health += 30;
		cout << "              > Smash that Kirby" << endl << "              > DANI's SWITCH  +350 Gold  +30 Health" << endl;
		break;
	case 7:
		myPlayer.gold -= 20;
		myPlayer.maxMoves += 1;
		myPlayer.maxHealth -= 20;
		myPlayer.health -= 20;
		cout << "              > AUCH!!" << endl << "              > ALEX's SLAP  -20 Gold  +1 Agility  -20 Health" << endl;
		break;
	case 8:
		myPlayer.gold += 700;
		myPlayer.maxStamina -= 20;
		myPlayer.stamina -= 20;
		cout << "              > Poor Guy..." << endl << "              > CRAMI’s LOL ACCOUNT  +700 Gold  -20 Health" << endl;
		break;
	case 9:
		myPlayer.gold -= 200;
		myPlayer.maxHealth -= 10;
		myPlayer.health -= 10;
		myPlayer.maxStamina -= 10;
		myPlayer.stamina -= 10;
		cout << "              > Mmmm suspicious..." << endl << "              > PAU's HACKED LINK  -200 Gold  -10 Health  -10 Stamina" << endl;
		break;
	case 10:
		myPlayer.gold += 25;
		myPlayer.maxHealth += 50;
		myPlayer.health += 50;
		myPlayer.maxStamina -= 30;
		myPlayer.stamina -= 30;
		cout << "              > To the Horny Jail" << endl << "              > MARCOS' WAIFU SHIRT  +25 Gold  +50 Health  -30 Stamina" << endl;
		break;

	case 11:
		myPlayer.gold += 4500;
		myPlayer.maxHealth += 1;
		myPlayer.health += 1;
		myPlayer.maxStamina += 1;
		myPlayer.stamina += 1;
		myPlayer.maxMoves += 1;
		cout << "              > Think Much Different" << endl << "              > MIVI's iPAD PRO  +4500 Gold  +1 Agility  +1 Health  +1 Stamina" << endl;
		break;

	default:
		break;
	}
}