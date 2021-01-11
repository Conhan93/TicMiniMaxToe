#ifndef ENGINE_INCLUDED
#define ENGINE_INCLUDED

#include "board.h"
#include "players.h"

class Engine
{
	private:
		Board* board;
		int turn;
		PlayerType player;

		int get_player();

		// checks
		bool horizontal_check(PlayerType player);
		bool vertical_check(PlayerType player);
		bool diagonal_check(PlayerType player);
	public:
		Engine() {};
		Engine(Board* board);

		void next_turn();
		bool make_move(int row, int col);
		bool check_win(PlayerType player);

		int get_turn();
		bool is_tie();
};

#endif
