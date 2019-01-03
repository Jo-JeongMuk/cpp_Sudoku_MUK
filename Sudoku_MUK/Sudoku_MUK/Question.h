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
	Question();
	char** Generate(char** answerNumbers, int numberOfBlank);
	void reset();
	~Question();
};