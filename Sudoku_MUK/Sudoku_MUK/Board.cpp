#include "pch.h"
#include "Board.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Board::Board(char **questionNumbers) 
{	
	for(int i = 0; i < ROW; ++i)
		for(int j = 0; j < COLUME; ++j){
			if(questionNumbers[i][j] == '0')
				board[(i * 2) + 4][(j * 4) + 7] = ' ';
			else 
				board[(i * 2) + 4][(j * 4) + 7] = questionNumbers[i][j];
		}
}

void Board::print(char **questionNumbers) const
{
	system("cls");
	cout << endl << endl;

	for(int i = 0; i < BOARD_COLUME; ++i){
		for(int j = 0; j < BOARD_ROW; ++j) {
			if (board[i][j] >= '1' && board[i][j] <= '9') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
				cout << board[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			}
			else cout << board[i][j];
		}
		cout << endl;
	}
}

Board::~Board(){}