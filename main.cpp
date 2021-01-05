#include <iostream>
#include "board.h"
#include "interface.h"
#include "engine.h"
#include <cmath>



int main()
{
	int turn = 1;
	Board board = Board(3);
	Interface UI = Interface(&board);
	Engine engine = Engine(&board);
	

	while (turn <= pow(board.getSize(),2))
	{
		UI.display_board(board);
		UI.make_move(turn);
		if (control.check_win(turn)) std::cout << "Win";
		turn++;
	}
	

}