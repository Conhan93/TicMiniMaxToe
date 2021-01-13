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
		bool horizontal_check(PlayerType player) const;
		bool vertical_check(PlayerType player) const;
		bool diagonal_check(PlayerType player) const;
		bool valid_move(int row, int col) const;
	public:
		Engine() {};
		Engine(Board* board);
		PlayerType get_player();

		void next_turn();
		bool make_move(int row, int col);
		bool check_win(PlayerType player) const;

		int get_turn();
		bool is_tie() const;
};

#endif
