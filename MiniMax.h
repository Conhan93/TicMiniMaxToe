#ifndef MINI_INCLUDED
#define MINI_INCLUDED
#include "board.h"
#include "engine.h"
#include "players.h"
#include "move.h"

class MiniMax
{
	private:

		enum Evaluation
		{
			GAME_NOT_FINISHED = -1,
			COMPUTER_WIN = 10,
			HUMAN_WIN = -10,
			TIE = 0,
		};

		Board* board;
		Engine* engine;
		int board_size;

		int min_search();
		int max_search();
		int evaluate_board();
	public:
		MiniMax() {};
		MiniMax(Board* board, Engine* engine);
		Move get_move();

};

#endif

