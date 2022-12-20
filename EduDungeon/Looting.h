#pragma once
#include "Scenes.h"
#include "Player.h"
#include "Chest.h"
#include "Math.h"
#include "Map.h"
#include <iostream>

void LootingScene(Scene& currentScene, Player& myPlayer, Chest Chests[], int whatChest, Map map[][5]);
void WhatGear(int numberOfGear, Player& myPlayer);