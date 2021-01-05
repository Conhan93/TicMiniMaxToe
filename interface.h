#include "board.h"
#include "tictactoe.h"


class Interface
{
	private:
		Board* board;
		Engine* engine;
	public:
		Interface() {};
		Interface(TicTacToe* game);
		void display_board(Board board) const;
		bool make_move(int turn);
};