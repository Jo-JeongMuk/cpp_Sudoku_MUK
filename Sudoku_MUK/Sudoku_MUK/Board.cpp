#include "pch.h"
#include "Board.h"

using namespace std;

Board::Board() {}

void Board::Print(char** questionNumbers, bool** setColors)
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
			if (j < 6 || j == 29 || j == 17 || j == 41 || j == 42 || i < 4 || i == 9 || i == 15 || i == 21) 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MAGENTA);
			if (j > 42) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			if (j > 68 && (board[i][j] == 'Q' || board[i][j] == 'W' || board[i][j] == 'E'))
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			if (i > 3 && (i-4)%2 == 0 && j > 6 && (j-7)%4 == 0 && setColors[(i-4)/2][(j-7)/4] == true)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
			cout << board[i][j];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		cout << endl;
	}
}

bool Board::EndGame(const clock_t start,const clock_t end) const
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