#include "pch.h"
#include "Level.h"

using namespace std;

int Level::Choose() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
		"                                         _         _ " << endl <<
		"                                        | |       | |" << endl <<
		"                         ____ _    _   _| | ____  | | ___  _   _" << endl <<
		"                        / ___| |  | |/ _  |/ __ ¡¬| |/  / | | | |" << endl <<
		"                        ¡¬__ ¡¬|__| | (_| || (_) ||   <   | |_| |" << endl <<
		"                        |____/¡¬____/¡¬___|¡¬____/|_|¡¬_¡¬¡¬____/" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	cout << endl << "                              Easy"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
	cout << "[1]";	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	cout << ", Medium";	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
	cout << "[2]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	cout << ", Hard"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
	cout << "[3]" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	cout << "                               Please select level : ";
	cin >> level;

	if (level == 1)
		numberOfBlank = LEVEL1;
	else if (level == 2)
		numberOfBlank = LEVEL2;
	else if (level == 3)
		numberOfBlank = LEVEL3;
	else
		Choose();

	return numberOfBlank;
}