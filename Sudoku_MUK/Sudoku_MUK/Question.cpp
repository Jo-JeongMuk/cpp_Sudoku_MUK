#include "pch.h"
#include "Question.h"

using namespace std;

Question::Question()
{
	questionNumbers = new char*[COLUMN];
	for (int i = 0; i < COLUMN; i++)
		questionNumbers[i] = new char[ROW];

	resetNumbers = new char*[COLUMN];
	for (int i = 0; i < COLUMN; i++)
		resetNumbers[i] = new char[ROW];
}

char** Question::Generate(char** answerNumbers, int numberOfBlank)
{
	for (int i = 0; i < COLUMN; ++i)
		for (int j = 0; j < ROW; ++j)
			questionNumbers[i][j] = answerNumbers[i][j];

	srand(time(NULL));
	for (int k = 0; k < numberOfBlank; ++k)
	{
		int i = rand() % COLUMN;
		int j = rand() % ROW;
		(questionNumbers[i][j] == '0') ? --k : questionNumbers[i][j] = '0';
	}

	for (int i = 0; i < COLUMN; ++i)
		for (int j = 0; j < ROW; ++j)
			resetNumbers[i][j] = questionNumbers[i][j];

	return questionNumbers;
}

void Question::reset()
{
	for (int i = 0; i < COLUMN; ++i)
		for (int j = 0; j < ROW; ++j)
			questionNumbers[i][j] = resetNumbers[i][j];
}

Question::~Question()
{
	for (int i = 0; i < COLUMN; ++i)
		delete[] questionNumbers[i];
	delete[] questionNumbers;

	for (int i = 0; i < COLUMN; i++)
		delete[] resetNumbers[i];
	delete[] resetNumbers;
}