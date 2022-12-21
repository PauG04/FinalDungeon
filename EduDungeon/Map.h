#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Chest.h"
#include <iostream>

struct Map
{
	bool isUsed;
	void Init();
};

void PrintMap(Player& myPlayer, Enemy Enemies[], Chest Chests[], Map map[][5], int numberOfEnemies);
void GeneratePositions(Player& myPlayer, Enemy Enemies[], Chest Chests[], Map map[][5], int numberOfEnemies);
void EnemiesSpawn(Enemy Enemies[], Map map[][5], int numberOfEnemies);
char PrintCharacter(int i, int j, Player& myPlayer, Enemy Enemies[], Chest Chests[], int numberOfEnemies);