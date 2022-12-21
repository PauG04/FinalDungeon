#include "Gameover.h"

void GameoverScene(Scene& currentScene, Player& myPlayer, string& name) {
	if (myPlayer.health <= 0) {
		cout << "- - - - - - GAMEOVER - - - - - -" << endl << endl << "You will need to be more spanish in order to complete the Dungeon!" << endl << " > Your final score is " << myPlayer.gold << endl << endl << "Thanks for playing :)"
			<< endl << endl << "A game made by Pau Giro & Alejandro Martinez" << endl << endl;
	}


	else {
		cout << "- - - - - - GAMEOVER - - - - - -" << endl << endl << "Good job " << name << "!! YOU FINISHED WITH ALL RADEV'S MINIONS! You can now pass to the 2nd course!!" << endl << " > Your final score is "
			<< myPlayer.gold << endl << endl << "Thanks for playing :)" << endl << endl << "A game made by Pau Giro & Alejandro Martinez" << endl << endl;
	}
	system("pause");
	system("cls");
	currentScene = START;
}
