#include "pch.h"
#include "Answer.h"

using namespace std;

Answer::Answer()
{
	answerNumbers = new char *[COLUMN];
	for (int i = 0; i < ROW; i++)
		answerNumbers[i] = new char[ROW];
}

char** Answer::Generate() 
{
	int RandomFileNumber = rand() % GAMECOUNT;
	string FileName[GAMECOUNT] = {"data\\1.txt", "data\\2.txt", "data\\3.txt", "data\\4.txt", "data\\5.txt", "data\\6.txt", "data\\7.txt", "data\\8.txt", "data\\9.txt"};
	char inputString[FILEBUFFER] = { 0, };
	ifstream inFile(FileName[RandomFileNumber]);
	
	if (!inFile.is_open()) {
		cout << " Error. There is no Answer File." << endl << " Please, check your Computer" << endl;
		exit(1);
	}

	while (!inFile.eof()) {
		inFile.getline(inputString, FILEBUFFER);
	} inFile.close();
	
	int count = 0;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			if (count %3 == 0) answerNumbers[i][j] = inputString[count] - KEY1;
			else if (count % 3 == 1) answerNumbers[i][j] = inputString[count] - KEY2;
			else answerNumbers[i][j] = inputString[count] - KEY3;
			++count;
		}

	return answerNumbers;
}

Answer::~Answer()
{
	for (int i = 0; i < COLUMN; i++)
		delete[] answerNumbers[i];
	delete answerNumbers;
}