#include "tictactoe.h"
#include "utils\players.h"
#include "utils\move.h"
#include <iostream>

TicTacToe::TicTacToe(int size)
{
	//this->board = Board(size);
	this->board = Board::get_board(size);
	//this->board
	this->engine = Engine();
	this->UI = Interface(&this->engine);
	this->AI = MiniMax(&this->engine);

}
void TicTacToe::start()
{
	UI.display_board();
	PlayerType player = PlayerType::HUMAN;
	PlayerType winner;
	bool win{ false };

	while (!win)
	{
		Move move;
		if (player == PlayerType::HUMAN)
		{

			move = UI.get_move();
			engine.make_move(move.row, move.col);
		}
		else
		{
			move = AI.get_move();
			engine.make_move(move.row, move.col);
			UI.display_board();

		}
		win = engine.check_win(player) || engine.is_tie();
		if(engine.check_win(player))
			winner = player;
		else if(engine.is_tie())
			winner = PlayerType::EMPTY;

		engine.next_turn();
		player = static_cast<PlayerType>((int)player * -1);
	}
	std::cout << (winner == PlayerType::EMPTY ? "Draw!" :
		winner == PlayerType::HUMAN ? "Human won!" : "Computer won!");
}
