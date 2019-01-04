#include "pch.h"
#include "input.h"

using namespace std;

Input::Input()
: reset_or_main(0) {
	cout << endl << "  Please Input Row Colume Value! : ";
	cin >> column;
	if (column == 'q' || column == 'Q') {
		reset_or_main = RETURN_TO_MAIN;
		return;
	}
	if (column == 'w' || column == 'W') {
		reset_or_main = RESET_GAME;
		return;
	}
	if (column == 'e' || column == 'E') {
		Board gameover;
		gameover.GameOver();
	}
	cin >> row >> value;
	column -= '1';
	row -= '1';
}

bool Input::ExpectionCheck() const
{
	if (row < 0 || row > 8 || column < 0 || column > 8 || value < '0' || value > '9')
	{
		cout << endl << "  It's whrong numbers. Please try again." << endl;
		Sleep(1500);
		return false;
	}
	return true;
}

bool Input::DuplicateCheck(char** questionNumbers) const
{
	if (value == '0')
		return true;
	else
		for (int i = 0; i < COLUMN; ++i)
			if (questionNumbers[column][i] == value || questionNumbers[i][row] == value)
				return false;
			else
				for (int i = 0; i < 3; ++i)
					if (questionNumbers[((column/3)*3)+i][row] == value || questionNumbers[column][((row/3)*3)+i] == value) {
						cout << endl << "  There already have '" << value << "'. Please try again." << endl;
						Sleep(1500);
						return false;
					}

	if (questionNumbers[column][row] != '0')
	{
		cout << endl;
		cout << "  There already have number. Please try again." << endl;
		Sleep(1500);
		return false;
	}

	return true;
}

void Input::FillintheBlank(char **questionNumbers)
{
	questionNumbers[column][row] = value;
}

bool Input::CheckEndOfGame(char** questionNumbers) const
{
	for(int i = 0; i < COLUMN; ++i)
		for(int j = 0; j < ROW; ++j)
			if (questionNumbers[i][j] == '0')
				return false;
	return true;
}