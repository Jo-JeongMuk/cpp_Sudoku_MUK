#pragma once

class Board
{
private:
	char board[BOARD_COLUME][BOARD_ROW] =
	{ "                                           ",
	  " ++=++===========+===========+===========++",
	  " || || 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 ||",
	  " ++=++===========+===========+===========++",
	  " ||1||   |   |   |   |   |   |   |   |   ||                       _         _ ",
	  " ++-++-----------+-----------+-----------++                      | |       | |",
	  " ||2||   |   |   |   |   |   |   |   |   ||       ____ _    _   _| | ____  | | ___  _   _",
	  " ++-++-----------+-----------+-----------++      / ___| |  | |/ _  |/ __ ��| |/  / | | | |",
	  " ||3||   |   |   |   |   |   |   |   |   ||      ��__ ��|__| | (_| || (_) ||   <   | |_| |",
	  " ++=++===========+===========+===========++      |____/��____/��___|��____/|_|��_����____/",
	  " ||4||   |   |   |   |   |   |   |   |   ||",
	  " ++-++-----------+-----------+-----------++",
	  " ||5||   |   |   |   |   |   |   |   |   ||    ++========================================++",
	  " ++-++-----------+-----------+-----------++    ||                                        ||",
	  " ||6||   |   |   |   |   |   |   |   |   ||    ||             % User Option %            ||",
	  " ++=++===========+===========+===========++    ||                                        ||",
	  " ||7||   |   |   |   |   |   |   |   |   ||    ||  1. Delete number  : Row Coloum 0      ||",
	  " ++-++-----------+-----------+-----------++    ||  2. Level reselect : Q                 ||",
	  " ||8||   |   |   |   |   |   |   |   |   ||    ||  3. Reset          : W                 ||",
	  " ++-++-----------+-----------+-----------++    ||  4. Exit           : E                 ||",
	  " ||9||   |   |   |   |   |   |   |   |   ||    ||                                        ||",
	  " ++=++===========+===========+===========++    ++========================================++"};
public:
	Board();
	void print(char **questionNumbers);
	~Board();
};