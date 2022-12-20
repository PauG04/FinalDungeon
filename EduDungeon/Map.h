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

void PrintMap(Player& myPlayer, Enemy Enemies[], Chest Chests[], Map map[][5]);
void GeneratePositions(Player& myPlayer, Enemy Enemies[], Chest Chests[], Map map[][5]);
void EnemiesSpawn(Enemy Enemies[], Map map[][5]);
char PrintCharacter(int i, int j, Player& myPlayer, Enemy Enemies[], Chest Chests[]);