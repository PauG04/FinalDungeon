#include "Enemy.h"

void Enemy::Init() {
	maxHealth = RandomNumber(60, 90);
	health = maxHealth;
	maxStamina = RandomNumber(60, 90);
	stamina = maxStamina;
	isDead = false;
}