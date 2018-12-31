#include "pch.h"
#include "Answer.h"
#include "Level.h"
#include "Question.h"
#include "Board.h"
int main()
{
	Answer Answer;
	Level Level;
	Question Question;
	Question.Generate(Answer.Generate(), Level.Choose());
	Board board;
	board.print(Question.questionNumbers);

	return 0;
}
