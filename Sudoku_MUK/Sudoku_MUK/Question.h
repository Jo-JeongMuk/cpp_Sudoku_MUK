#pragma once

class Question
{
private:
	char **resetNumbers;

public:
	char **questionNumbers;
	Question();
	char** Generate(char** answerNumbers, int numberOfBlank);
	char** reset();
	~Question();
};