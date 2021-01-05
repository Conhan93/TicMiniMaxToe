#include "tictactoe.h"
#include <cmath>


TicTacToe::TicTacToe(int size)
{
	this->board = Board(size);
	this->engine = Engine(&this->board);
	this->UI = Interface(this);
	
}
void TicTacToe::start()
{
	while (engine.get_turn() < pow(board.getSize(),2))
	{
		UI.make_move();
		engine.next_turn();
	}
}
