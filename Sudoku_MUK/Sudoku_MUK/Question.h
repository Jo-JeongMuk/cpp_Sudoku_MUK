#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

class Question
{
private:
	char** resetNumbers;
public:
	char **questionNumbers;
	bool** setColors;
	Question();
	char** Generate(char** answerNumbers, const int numberOfBlank);
	void reset();
	~Question();
};