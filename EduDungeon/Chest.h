#pragma once
#include "Math.h"

struct Chest {
	
	int X;
	int Y;

	int item;
	int gold;
	int isPotion;
	bool isOpen;
	void Init();


};