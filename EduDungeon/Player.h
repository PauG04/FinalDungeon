#pragma once
#include "Math.h"

struct Player
{
	int X;
	int Y;

	int maxHealth;
	int health;
	int maxStamina;
	int stamina;
	int usedStamina;
	int gold;
	int potions;
	int maxMoves;
	int moves;

	void Init();
};