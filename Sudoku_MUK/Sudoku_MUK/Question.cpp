#include "pch.h"
#include "Question.h"
#include <iostream>
#include <ctime>

using namespace std;

Question::Question()
{
	questionNumbers = new char*[ROW];
	for (int i = 0; i < ROW; i++)
		questionNumbers[i] = new char[COLUME];

	resetNumbers = new char*[ROW];
	for (int i = 0; i < ROW; i++)
		resetNumbers[i] = new char[COLUME];
}

char** Question::Generate(char** answerNumbers, int numberOfBlank)
{
	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COLUME; ++j)
			questionNumbers[i][j] = answerNumbers[i][j];

	srand(time(0));
	for (int k = 0; k < numberOfBlank; ++k)
	{
		int i = rand() % ROW;
		int j = rand() % COLUME;
		(questionNumbers[i][j] == '0') ? --k : questionNumbers[i][j] = '0';
	}

	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COLUME; ++j)
			resetNumbers[i][j] = questionNumbers[i][j];

	return questionNumbers;
}

char** Question::reset()
{
	return resetNumbers;
}

Question::~Question()
{
	for (int i = 0; i < ROW; ++i)
		delete[] questionNumbers[i];
	delete[] questionNumbers;

	for (int i = 0; i < ROW; i++)
		delete[] resetNumbers[i];
	delete[] resetNumbers;
}