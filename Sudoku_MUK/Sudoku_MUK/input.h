#pragma once

#include "Board.h"
#include <iostream>
#include <Windows.h>

class Input
{
private:
	char column;
	char row;
	char value;

public:
	Input();
	int reset_or_main;
	bool ExpectionCheck() const;
	bool DuplicateCheck(char** questionNumbers) const;
	void FillintheBlank(char** questionNumbers);
	bool CheckEndOfGame(char** questionNumbers) const;
};
