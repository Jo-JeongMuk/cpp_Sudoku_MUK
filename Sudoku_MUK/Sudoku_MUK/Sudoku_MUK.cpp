#include "pch.h"
#include "Answer.h"
#include "Level.h"
#include "Question.h"

int main()
{
	Answer Answer;
	Level Level;
	Question Question;
	Question.Generate(Answer.Generate(), Level.Choose());

	return 0;
}
