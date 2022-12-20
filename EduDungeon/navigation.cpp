#include "Navigation.h"

void NavigationScene(Scene& currentScene, Player& myPlayer, Enemy Enemies[], Chest Chests[], Map map[][5], int& whatEnemy, int& whatChest) {
	
	bool validCommand = false;
	while (!validCommand) {
		if (myPlayer.health > 0) {
			if (EnemiesAlive(Enemies) || ChestsClosed(Chests)) {
				if (myPlayer.moves == 0) {
					for (int i = 0; i < 5; i++) {
						map[Enemies[i].X][Enemies[i].Y].isUsed = false;
					}
					map[myPlayer.X][myPlayer.Y].isUsed = true;
					EnemiesSpawn(Enemies, map);
					myPlayer.moves = myPlayer.maxMoves;
				}
				cout << "------DUNGEON------\n\n E-- > Enemy    P-- > Player    C-- > Chest\n\nHealth:" << myPlayer.health << " / " << myPlayer.maxHealth << "\nPotions: "
					<< myPlayer.potions << " / " << MaxPotions << "\nMoves: " << myPlayer.moves << " / " << myPlayer.maxMoves;
				PrintMap(myPlayer, Enemies, Chests, map);
				cout << "____________________\n\nW A S D --> Move\nP --> Potion\nEnter your action: ";

				char navigationAction;
				cin >> navigationAction;
				PlayerAction(navigationAction, myPlayer, map, validCommand);

				EnemyFound(myPlayer, Enemies, currentScene, whatEnemy);
				ChestFound(myPlayer, Chests, currentScene, whatChest);
			}
			else {
				currentScene = GAMEOVER;
				validCommand = true;
			}
		}
		else {
			currentScene = GAMEOVER;
			validCommand = true;
		}
		system("cls");

	}


}

void PlayerAction(char& navigationAction, Player& myPlayer, Map map[][5], bool& validCommand) {
	map[myPlayer.X][myPlayer.Y].isUsed = false;

	if (navigationAction == 'W' && myPlayer.X != 0) {
		myPlayer.moves--;
		myPlayer.Y -= 1;
		validCommand = true;
	}
	else if (navigationAction == 'A' && myPlayer.X != 0) {
		myPlayer.moves--;
		validCommand = true;
		myPlayer.X -= 1;
	}
	else if (navigationAction == 'S' && myPlayer.Y != 4) {
		myPlayer.moves--;
		validCommand = true;
		myPlayer.Y += 1;
	}
	else if (navigationAction == 'D' && myPlayer.X != 4) {
		myPlayer.moves--;
		validCommand = true;
		myPlayer.X += 1;
	}
	else if (navigationAction == 'P' && myPlayer.potions > 0)
	{
		myPlayer.health += (myPlayer.maxHealth * 0.4);
		TooMuchHealth(myPlayer.health, myPlayer.maxHealth);
		validCommand = true;
		myPlayer.potions--;
		myPlayer.moves--;
	}
	else {
		cout << "Invalid Command!!" << endl;
		system("pause");
	}
	map[myPlayer.X][myPlayer.Y].isUsed = true;

}

void EnemyFound(Player& myPlayer, Enemy Enemies[], Scene& currentScene, int& whatEnemy) {
	for (int i = 0; i < 5; i++) {
		if (myPlayer.X == Enemies[i].X && myPlayer.Y == Enemies[i].Y) {
			currentScene = COMBAT;
			whatEnemy = i;
		}
	}
}

void ChestFound(Player& myPlayer, Chest Chests[], Scene& currentScene, int& whatChest) {
	for (int i = 0; i < 2; i++) {
		if (myPlayer.X == Chests[i].X && myPlayer.Y == Chests[i].Y) {
			currentScene = LOOTING;
			whatChest = i;
		}
	}
}

bool EnemiesAlive(Enemy Enemies[]) {
	for (int i = 0; i < 5; i++)
		if (!Enemies[i].isDead)
			return true;
	return false;
}

bool ChestsClosed(Chest Chests[]) {
	for (int i = 0; i < 2; i++)
		if (!Chests[i].isOpen)
			return true;
	return false;
}
