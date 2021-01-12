#ifndef ENGINE_INCLUDED
#define ENGINE_INCLUDED

#include "board.h"
#include "players.h"
#include "move.h"

class Engine
{
	private:
		Board* board;
		int turn;
		PlayerType player;

		

		// checks
		bool horizontal_check(PlayerType player);
		bool vertical_check(PlayerType player);
		bool diagonal_check(PlayerType player);
		bool valid_move(int row, int col);
	public:
		Engine() {};
		Engine(Board* board);
		PlayerType get_player();

		void next_turn();
		bool make_move(int row, int col);
		bool check_win(PlayerType player);

		int get_turn();
		bool is_tie();
};

#endif
