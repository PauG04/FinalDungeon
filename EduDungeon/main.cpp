#include "Main.h"

//no hi ha enemics randoms
int main() {
	srand(time(NULL));

	system("color 0A");

	Scene currentScene = START;

	bool isPlaying = true;


	while (isPlaying)
	{
		Player myPlayer;
		myPlayer.Init();

		int numberOfEnemies = RandomNumber(5, 7);
		Enemy Enemies[7];
		for (int i = 0; i < numberOfEnemies; i++)
			Enemies[i].Init();

		Chest Chests[2];
		for (int i = 0; i < 2; i++)
			Chests[i].Init();

		Map map[5][5];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				map[j][i].Init();

		int whatEnemy = 0, whatChest = 0;
		string name;

		GeneratePositions(myPlayer, Enemies, Chests, map, numberOfEnemies);

		bool finished = false;

		while (!finished) {
			switch (currentScene)
			{
			case START:
				StartScene(currentScene, name);
				break;
			case NAVIGATION:
				NavigationScene(currentScene, myPlayer, Enemies, Chests, map, whatEnemy, whatChest, numberOfEnemies);
				break;
			case COMBAT:
				CombatScene(currentScene, myPlayer, Enemies, whatEnemy, map);
				break;
			case LOOTING:
				LootingScene(currentScene, myPlayer, Chests, whatChest, map);
				break;
			case GAMEOVER:
				GameoverScene(currentScene, myPlayer, name);
				finished = true;
				break;

			default:
				break;
			}
		}

	}
	










	return 0;
}