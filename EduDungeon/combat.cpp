#include "Combat.h"

void CombatScene(Scene& currentScene, Player& myPlayer, Enemy Enemies[], int whatEnemy, Map map[][5]) {
	while (currentScene == COMBAT) {
		cout << "-------- COMBAT --------" << endl << endl << "-- Enemy --" << endl;
		bar(Enemies[whatEnemy].health, Enemies[whatEnemy].maxHealth);
		cout << " ? HP" << endl;

		if (Enemies[whatEnemy].stamina == 0)
			cout << " [          ]";
		else
			bar(Enemies[whatEnemy].stamina, Enemies[whatEnemy].maxStamina);
		cout << " ? Stamina" << endl;

		cout << endl << endl << "------------------" << endl << endl << "-- Player --" << endl;

		bar(myPlayer.health, myPlayer.maxHealth);
		cout << ' ' << myPlayer.health << '/' << myPlayer.maxHealth << " HP" << endl;

		if (myPlayer.stamina == 0)
			cout << " [          ]";
		else
			bar(myPlayer.stamina, myPlayer.maxStamina);
		cout << ' ' << myPlayer.stamina << '/' << myPlayer.maxStamina << " Stamina" << endl;

		cout << endl << "Potions: " << myPlayer.potions << '/' << MaxPotions;

		cout << endl << endl << "____________________________________________________" << endl << endl << "A --> Attack" << endl << "D --> Defend" << endl
			<< "R --> Rest" << endl << "P --> Potion" << endl << endl << "Enter your action: ";

		char combatAction;
		cin >> combatAction;

		char enemyAction;
		if (Enemies[whatEnemy].health < (Enemies[whatEnemy].maxHealth * 0.3) && Enemies[whatEnemy].stamina < (Enemies[whatEnemy].maxStamina * 0.3))
			enemyAction = 'D';
		else if (Enemies[whatEnemy].stamina < (Enemies[whatEnemy].maxStamina * 0.2))
			enemyAction = 'R';
		else
			enemyAction = 'A';

		Enemies[whatEnemy].usedStamina = RandomNumber(Enemies[whatEnemy].stamina * 0.2, Enemies[whatEnemy].stamina);

		switch (combatAction) {
		case 'A':
			cout << endl << "Enter the attack value (Max " << myPlayer.stamina << "): ";
			cin >> myPlayer.usedStamina;

			if (enemyAction == 'A')//attack vs attack
			{
				if (myPlayer.usedStamina >= Enemies[whatEnemy].usedStamina)//utilitzes += stamina q l'enemic
				{
					printf("\nYou strike the enemy with more force! The enemy recieves %d damage\n", myPlayer.usedStamina);
					myPlayer.stamina -= myPlayer.usedStamina;
					Enemies[whatEnemy].stamina -= Enemies[whatEnemy].usedStamina;
					Enemies[whatEnemy].health -= myPlayer.usedStamina;
				}

				if (myPlayer.usedStamina < Enemies[whatEnemy].usedStamina)//enemic utilitza + stamina
				{
					printf("The enemy strikes with more force! You recieve %d damage\n", Enemies[whatEnemy].usedStamina);
					Enemies[whatEnemy].stamina -= Enemies[whatEnemy].usedStamina;
					myPlayer.stamina -= myPlayer.usedStamina;
					myPlayer.health -= Enemies[whatEnemy].usedStamina;
				}
			}

			else if (enemyAction == 'D')//attack vs defend
			{
				myPlayer.stamina -= myPlayer.usedStamina;
				myPlayer.usedStamina *= 0.4;
				Enemies[whatEnemy].health -= myPlayer.usedStamina;
				printf("\n\nThe enemy blocks your attack, receiving only %d damage\n", myPlayer.usedStamina);
				Enemies[whatEnemy].stamina += (Enemies[whatEnemy].maxStamina * 0.25);
				Enemies[whatEnemy].usedStamina = Enemies[whatEnemy].stamina;

			}

			else if (enemyAction == 'R')//attack vs rest
			{
				printf("You strike the unprepared enemy dealing % d damage!\n", myPlayer.usedStamina);
				Enemies[whatEnemy].health -= myPlayer.usedStamina;
				myPlayer.stamina -= myPlayer.usedStamina;
				Enemies[whatEnemy].stamina = Enemies[whatEnemy].maxStamina;
				Enemies[whatEnemy].usedStamina = Enemies[whatEnemy].stamina;
			}
			break;

		case 'D':
			if (enemyAction == 'A')//defend vs attack
			{
				Enemies[whatEnemy].stamina -= Enemies[whatEnemy].usedStamina;
				Enemies[whatEnemy].usedStamina *= 0.4;
				printf("\nYou defend the enemy blow, but receive %d damage\n", Enemies[whatEnemy].usedStamina);
				myPlayer.health -= Enemies[whatEnemy].usedStamina;
				myPlayer.stamina += (myPlayer.maxStamina * 0.25);

			}


			else if (enemyAction == 'D')//defend vs defend
			{
				printf("You both defend!\n");
				myPlayer.stamina += (myPlayer.maxStamina * 0.25);
				Enemies[whatEnemy].stamina += (Enemies[whatEnemy].maxStamina * 0.25);
				Enemies[whatEnemy].usedStamina = Enemies[whatEnemy].stamina;
			}

			else if (enemyAction == 'R')//defend vs rest
			{
				printf("You defend while the enemy catches a breath! It seems ready to strike!\n");
				myPlayer.stamina += (myPlayer.maxStamina * 0.25);
				Enemies[whatEnemy].stamina = Enemies[whatEnemy].maxStamina;
				Enemies[whatEnemy].usedStamina = Enemies[whatEnemy].stamina;

			}

			if (myPlayer.stamina > myPlayer.maxStamina)//pq la stamina no sobrepassi la stamina maxima
			{
				myPlayer.stamina = myPlayer.maxStamina;
				myPlayer.usedStamina = myPlayer.stamina;

			}

			break;

		case 'R':
			if (enemyAction == 'A')//rest vs attack
			{
				printf("You rest when the enemy hits you, striking for %d damage\n", Enemies[whatEnemy].usedStamina);
				myPlayer.health -= Enemies[whatEnemy].usedStamina;
				myPlayer.stamina = myPlayer.maxStamina;
				Enemies[whatEnemy].stamina -= Enemies[whatEnemy].usedStamina;
			}

			else if (enemyAction == 'D')//rest vs defend
			{
				printf("You rest while the enemy defends, gaining some advantage!\n");
				myPlayer.stamina = myPlayer.maxStamina;
				Enemies[whatEnemy].stamina += (Enemies[whatEnemy].maxStamina * 0.25);
				myPlayer.usedStamina = myPlayer.stamina;
			}

			else if (enemyAction == 'R')//rest vs rest
			{
				printf("You both rest, gathering up for a clash!\n");
				myPlayer.stamina = myPlayer.maxStamina;
				Enemies[whatEnemy].stamina = Enemies[whatEnemy].maxStamina;
				myPlayer.usedStamina = myPlayer.stamina;
			}

			break;

		case 'P':
			if (myPlayer.potions > 0)
			{
				if (enemyAction == 'A')
				{
					printf("You drink the potion when the enemy hits you, striking for %d damage\n", Enemies[whatEnemy].usedStamina);
					myPlayer.health += (myPlayer.maxHealth * 0.4);
					myPlayer.health -= Enemies[whatEnemy].usedStamina;
					Enemies[whatEnemy].stamina -= Enemies[whatEnemy].usedStamina;
				}

				else if (enemyAction == 'D')
				{
					printf("You drink the potion while the enemy defends, feeling renewed!\n");
					myPlayer.health += (myPlayer.maxHealth * 0.4);
					Enemies[whatEnemy].stamina += (Enemies[whatEnemy].maxStamina * 0.25);
				}

				else if (enemyAction == 'R')
				{
					printf("The enemy observes how you drink the potion.\n");
					myPlayer.health += (myPlayer.maxHealth * 0.4);
					Enemies[whatEnemy].stamina = Enemies[whatEnemy].maxStamina;
				}
				TooMuchHealth(myPlayer.health, myPlayer.maxHealth);
				myPlayer.potions--;
			}
			else
				printf("You have no potions. "); //reiniciar bucle, tornar al scanf_s de playerAction

			break;

		default:
			printf("Enter a valid command! ");
			break;
		}
		
		if (Enemies[whatEnemy].health <= 0) {
			map[Enemies[whatEnemy].X][Enemies[whatEnemy].Y].isUsed = false;
			Enemies[whatEnemy].X += 10;
			Enemies[whatEnemy].Y += 10;
			myPlayer.gold += RandomNumber(50, 100);
			cout << endl << "This minion is no more." << endl;
			Enemies[whatEnemy].isDead = true;
			currentScene = NAVIGATION;
		}
		
		else if (myPlayer.health <= 0) {
			myPlayer.gold -= 200;
			cout << endl << "You lost your life to one of Radev's minion!" << endl;
			currentScene = NAVIGATION;
		}
	
		system("pause");
		system("cls");
	}

	
}

void bar(int barLenght, int maxBarLenght) {//barres vida i stamina

	cout << " [";
	for (int digits = (barLenght * 10 / maxBarLenght) + 1; digits > 0; digits--)
		cout << '=';
	for (int digits = (barLenght * 10 / maxBarLenght) + 1; digits < 10; digits++)
		cout << ' ';
	cout << ']';
}