#include "pch.h"
#include "Board.h"

using namespace std;

Board::Board() 
{
//	setColors = new bool*[COLUMN];
//	for (int i = 0; i < COLUMN; i++)
//		setColors[i] = new bool[ROW];
}

void Board::Print(char **questionNumbers)
{
	for(int i = 0; i < COLUMN; ++i)
		for(int j = 0; j < ROW; ++j)
			if(questionNumbers[i][j] == '0')
				board[(i * 2) + 4][(j * 4) + 7] = ' ';
			else
				board[(i * 2) + 4][(j * 4) + 7] = questionNumbers[i][j];
	system("cls");
	cout << endl << endl;

	for(int i = 0; i < BOARD_COLUMN; ++i){
		for(int j = 0; j < BOARD_ROW; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

bool Board::EndGame(clock_t start, clock_t end) const
{
	clock_t min = ((end - start) / CLOCKS_PER_SEC / 60) % 60;
	clock_t sec = (end - start) / CLOCKS_PER_SEC % 60;

	system("cls");

	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
	cout << "                                  Time : " << min % 60 << " minutes  " << sec << " seconds" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	cout << "                         __     ___      __    __    ____     ___  " << endl <<
			"                        |  |   |   |    |  |  |  |  |    ¡¬   |  | " << endl <<
			"                        |  |   |   |    |  |  |  |  |     ¡¬  |  | " << endl <<
			"                        ¡¬ ¡¬  /    ¡¬  /  /  |  |  |  |¡¬ ¡¬ |  | " << endl <<
			"                         ¡¬ ¡¬/  /¡¬ ¡¬/  /   |  |  |  | ¡¬ ¡¬|  | " << endl <<
			"                          ¡¬____/  ¡¬____/    |__|  |__|  ¡¬_____| "  << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
	cout << endl << "                                 Thank you for enjoying!!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	exit(1);
}

void Board::GameOver() const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	cout << "               _____           __   ___ ______    ______       ________ _____  " << endl <<
            "              / ____|   /¡¬   |  ¡¬/   |  ____|  / __ ¡¬¡¬    / /  ____|  __ ¡¬ " << endl <<
			"             | |  __   /  ¡¬  | ¡¬   / | |__    | |  | ¡¬¡¬  / / | |__  | |__) | " << endl <<
			"             | | |_ | / /¡¬¡¬ |  |¡¬/| |  __|   | |  | |¡¬¡¬/ /  |  __| |  _  /  " << endl <<
			"             | |__| |/ ____ ¡¬|  |   | | |____  | |__| | ¡¬  /   | |____| |¡¬¡¬  " << endl <<
			"             ¡¬_____/_/    ¡¬_¡¬_|   |_|______|  ¡¬____/  ¡¬/    |______|_| ¡¬_¡¬ " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	exit(1);
}

Board::~Board(){}