#include "pch.h"
#include "input.h"

using namespace std;

Input::Input()
: reset_or_main(0) {
	cout << endl << "  Please Input Row Colume Value! : ";
	cin >> _column;
	if (_column == 'q' || _column == 'Q') {
		reset_or_main = RETURN_TO_MAIN;
		return;
	}
	if (_column == 'w' || _column == 'W') {
		reset_or_main = RESET_GAME;
		return;
	}
	if (_column == 'e' || _column == 'E') {
		Board gameover;
		gameover.GameOver();
	}
	cin >> _row >> _value;
	_column -= '1';
	_row -= '1';
}

bool Input::ExpectionCheck()
{
	if (_row < 0 || _row > 8 || _column < 0 || _column > 8 || _value < '0' || _value > '9')
	{
		cout << endl << "  It's whrong numbers. Please try again." << endl;
		Sleep(1000);
		return false;
	}
	return true;
}

bool Input::DuplicateCheck(char **questionNumbers)
{
	if (questionNumbers[_column][_row] != '0')
	{
		cout << endl;
		cout << "  There already have number. Please try again." << endl;
		Sleep(1000);
		return false;
	}
	if (_value != '0')
		for (int i = 0; i < COLUMN; ++i)
			if (questionNumbers[_column][i] == _value || questionNumbers[i][_row] == _value)
				return false;
			else
				for (int i = 0; i < 3; ++i)
					if (questionNumbers[((_column / 3) * 3) + i][_row] == _value || questionNumbers[_column][((_row / 3) * 3) + i] == _value) {
						cout << endl << "  There already have '" << _value << "'. Please try again." << endl;
						Sleep(1000);
						return false;
					}
	return true;
}

void Input::FillintheBlank(char **questionNumbers)
{
	questionNumbers[_column][_row] = _value;
}