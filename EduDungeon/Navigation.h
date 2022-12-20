#pragma once
#include "Scenes.h"
#include "Player.h"
#include "Enemy.h"
#include "Chest.h"
#include <iostream>
#include "Map.h"

void PlayerAction(char& navigationAction, Player& myPlayer, Map map[][5], bool& validCommand);
void NavigationScene(Scene& currentScene, Player& myPlayer, Enemy Enemies[], Chest Chests[], Map map[][5], int& whatEnemy, int& whatChest);
void EnemyFound(Player& myPlayer, Enemy Enemies[], Scene& currentScene, int& whatEnemy);
void ChestFound(Player& myPlayer, Chest Chests[], Scene& currentScene, int& whatChest);
bool EnemiesAlive(Enemy Enemies[]);
bool ChestsClosed(Chest Chests[]);
