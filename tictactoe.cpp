#include "tictactoe.h"
#include "utils\players.h"
#include "utils\move.h"
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
	PlayerType player = PlayerType::HUMAN;
	bool win{ false };

	while (!win)
	{
		Move move;
		if (player == PlayerType::HUMAN)
		{

			UI.make_move();
		}
		else
		{
			move = AI.get_move();
			engine.make_move(move.row, move.col);
			UI.display_board();

		}
		win = engine.check_win(player) || engine.is_tie();

		engine.next_turn();
		player = static_cast<PlayerType>((int)player * -1);
	}
	std::cout << "game ova";
}
