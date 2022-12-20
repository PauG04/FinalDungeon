#include "Start.h"

void StartScene(Scene& currentScene, string& name) {
	
	cout << "Type your Name: ";
	cin >> name;
	
	currentScene = NAVIGATION;
	
	system("pause");
	system("cls");

}