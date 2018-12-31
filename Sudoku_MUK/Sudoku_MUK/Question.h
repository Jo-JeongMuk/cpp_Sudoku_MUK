#pragma once
#include "Answer.h"

class Question : public Answer
{
private:
	char **questionNumbers;
	char **resetNumbers;

public:
	Question();
	char** Generate(char** answerNumbers, int numberOfBlank);
	char** reset();
	~Question();
};