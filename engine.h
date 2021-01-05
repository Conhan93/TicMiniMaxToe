#pragma once

#include "board.h"

class Engine
{
	private:
		Board* board;
		int turn;

		int get_player();
	public:
		Engine() {};
		Engine(Board* board);

		void next_turn();
		bool make_move(int row, int col);
		bool check_win();

		int get_turn();
};

