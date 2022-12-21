#include "Map.h"

void PrintMap(Player& myPlayer, Enemy Enemies[], Chest Chests[], Map map[][5], int numberOfEnemies) {
	cout << endl;
	//TOP PART
	for (int i = 0; i < 5; i++)
		cout << " ___ ";
	cout << endl;

	//PRINT ROWS
	for (int i = 0; i < 5; i++) {
		//TOP PART
		for (int j = 0; j < 5; j++) {
			cout << "|   |";
		}
		cout << endl;
		//MIDDLE PART
		for (int j = 0; j < 5; j++) {
			cout << "| " << PrintCharacter(i, j, myPlayer, Enemies, Chests, numberOfEnemies) << " |";

		}
		cout << endl;
		for (int j = 0; j < 5; j++)
			cout << "|___|";
		cout << endl;
	}
}

void GeneratePositions(Player& myPlayer, Enemy Enemies[], Chest Chests[], Map map[][5], int numberOfEnemies) {
	map[myPlayer.X][myPlayer.Y].isUsed = true;
	
	EnemiesSpawn(Enemies, map, numberOfEnemies);

	for (int i = 0; i < 2; i++) {
		do {
			Chests[i].X = RandomNumber(0, 4);
			Chests[i].Y = RandomNumber(0, 4);
		} while (map[Chests[i].X][Chests[i].Y].isUsed);
		map[Chests[i].X][Chests[i].Y].isUsed = true;
	}

}

void EnemiesSpawn(Enemy Enemies[], Map map[][5], int numberOfEnemies) {
	for (int i = 0; i < numberOfEnemies; i++) {
		if (!Enemies[i].isDead) {
			do {
				Enemies[i].X = RandomNumber(0, 4);
				Enemies[i].Y = RandomNumber(0, 4);
			} while (map[Enemies[i].X][Enemies[i].Y].isUsed);
			map[Enemies[i].X][Enemies[i].Y].isUsed = true;
		}
	}
}

char PrintCharacter(int i, int j, Player& myPlayer, Enemy Enemies[], Chest Chests[], int numberOfEnemies) {
	if (myPlayer.X == j && myPlayer.Y == i)
		return 'P';
	for (int k = 0; k < numberOfEnemies; k++) {
		if (Enemies[k].X == j && Enemies[k].Y == i)
			return 'E';
	}
	for (int k = 0; k < 2; k++) {
		if (Chests[k].X == j && Chests[k].Y == i)
			return 'C';
	}
	return ' ';
}

void Map::Init() {
	isUsed = false;
}