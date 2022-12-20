#include "Math.h"

int RandomNumber(int min, int max) {
	int result = rand() % (max - min + 1) + min;
	return result;
}

void TooMuchHealth(int& health, int& maxHealth) {
	if (health > maxHealth)
		health = maxHealth;
}