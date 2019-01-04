#pragma once

#include <fstream>
#include <iostream>
#include <string>

#define GAMECOUNT 9
#define FILEBUFFER 100
#define KEY1 20
#define KEY2 25
#define KEY3 30

class Answer
{
private:
	char** answerNumbers;
public:
	Answer();
	char** Generate();
	~Answer();
};