#include "Player.h"

void Player::Init() {
	X = 2;
	Y = 3;
	maxHealth = RandomNumber(900, 1100);
	health = maxHealth;
	maxStamina = RandomNumber(900, 1100);
	stamina = maxStamina;
	maxMoves = 3;
	moves = 3;
	gold = 0;
	potions = 3;
}