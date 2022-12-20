#pragma once
#include "Scenes.h"
#include "Player.h"
#include "Enemy.h"
#include "Math.h"
#include "Map.h"
#include <iostream>

void CombatScene(Scene& currentScene, Player& myPlayer, Enemy Enemies[], int whatEnemy, Map map[][5]);
void bar(int barLenght, int maxBarLenght);