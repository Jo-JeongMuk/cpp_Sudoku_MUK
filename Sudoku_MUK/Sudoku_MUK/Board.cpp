#include "pch.h"
#include "Board.h"
#include "Question.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Board::Board()
{
}

void Board::print(char **questionNumbers)
{
	system("cls");
	cout << endl << endl;

	for(int i = 0; i < ROW; ++i)
		for(int j = 0; j < COLUME; ++j){
			if(questionNumbers[i][j] == '0')
				board[(i * 2) + 4][(j * 4) + 7] = ' ';
			else 
				board[(i * 2) + 4][(j * 4) + 7] = questionNumbers[i][j];
		}

	for(int i = 0; i < BOARD_COLUME; ++i){
		for(int j = 0; j < BOARD_ROW; ++j)
			cout << board[i][j];
		cout << endl;
	}

}

Board::~Board()
{
}