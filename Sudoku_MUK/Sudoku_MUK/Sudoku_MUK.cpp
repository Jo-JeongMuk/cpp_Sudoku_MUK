#include "pch.h"
#include "Answer.h"
#include "Level.h"
#include "Question.h"
#include "Board.h"
#include "input.h"
#include <windows.h>
#include <ctime>

int main()
{
	system("mode con: cols=92 lines=30");
	Answer answer;
	Level level;
	Question question;

	while (true){
		question.Generate(answer.Generate(), level.Choose());
		Board board;
		clock_t start, end;
		start = clock();

		while(true) {
			board.Print(question.questionNumbers, question.setColors);
			Input input;
			if(input.reset_or_main == RETURN_TO_MAIN)
				break;
			else if(input.reset_or_main == RESET_GAME)
				question.reset();
			else if(input.reset_or_main == EXIT_GAME)
				return board.GameOver();
			else if(input.ExpectionCheck() == true && input.DuplicateCheck(question.questionNumbers) == true)
				input.FillintheBlank(question.questionNumbers);
			if (input.CheckEndOfGame(question.questionNumbers)) {
				end = clock();
				if(board.EndGame(start, end))
					break;
			}
		}
	}
	return 0;
}