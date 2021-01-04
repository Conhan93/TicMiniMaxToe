#include <iostream>
#include "board.h"
#include "interface.h"
#include <cmath>



int main()
{
	int turn = 1;
	Board board = Board(3);
	Interface UI = Interface(&board);
	

	while (turn <= pow(board.getSize(),2))
	{
		UI.display_board(board);
		UI.make_move(turn);
		turn++;
	}
	

}