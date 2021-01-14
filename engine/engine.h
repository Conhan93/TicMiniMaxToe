#ifndef ENGINE_INCLUDED
#define ENGINE_INCLUDED

#include "..\board\board.h"
#include "..\utils\players.h"
#include "..\utils\move.h"

class Engine
{
	private:
		Board* board;
		PlayerType player;

		// checks
		bool horizontal_check(PlayerType player) const;
		bool vertical_check(PlayerType player) const;
		bool diagonal_check(PlayerType player) const;
		bool valid_move(int row, int col) const;
	public:
		Engine();
		//Engine(Board* board);
		PlayerType get_player();

		void next_turn();
		bool make_move(int row, int col);
		bool check_win(PlayerType player) const;

		bool is_tie() const;
};

#endif
