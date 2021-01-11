#include "tictactoe.h"
#include "players.h"
#include "move.h"
#include <cmath>
#include <iostream>

TicTacToe::TicTacToe(int size)
{
	this->board = Board(size);
	this->engine = Engine(&this->board);
	this->UI = Interface(&this->board,&this->engine);
	this->AI = MiniMax(&this->board, &this->engine);
	
}
void TicTacToe::start()
{
	UI.display_board();
	while (!engine.is_tie() && !engine.check_win(static_cast<PlayerType>(engine.get_turn())))
	{
		Move move;
		if (engine.get_turn() % 2)
		{
			
			UI.make_move();
		}
		else
		{
			move = AI.get_move();
			engine.make_move(move.row, move.col);
			UI.display_board();
			
		}

		
		engine.next_turn();
	}
	std::cout << "game ova";
}
