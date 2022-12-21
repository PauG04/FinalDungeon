#include "Start.h"

void StartScene(Scene& currentScene, string& name) {
	cout << "Welcome to the 1st year of CDI Dungeon." << endl << "The Conservatives will help you to pass (or at least try it) with customed items." << 
		endl << "But watch out for Radev's Minions, also known as teachers." << endl << endl << "Type your Name to open the door: ";
	cin >> name;
	
	currentScene = NAVIGATION;
	
	system("pause");
	system("cls");

}