#include "Player.h"

void Player::Init() {
	X = 2;
	Y = 3;
	maxHealth = RandomNumber(90, 110);
	health = maxHealth;
	maxStamina = RandomNumber(90, 110);
	stamina = maxStamina;
	maxMoves = 3;
	moves = 3;
	gold = 0;
	potions = 3;
}