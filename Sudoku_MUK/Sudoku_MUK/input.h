#pragma once

#include "Board.h"
#include <iostream>
#include <Windows.h>

class Input
{
private:
	char _column;
	char _row;
	char _value;

public:
	Input();
	int reset_or_main;
	bool ExpectionCheck();
	bool DuplicateCheck(char **questionNumbers);
	void FillintheBlank(char **questionNumbers);
};
