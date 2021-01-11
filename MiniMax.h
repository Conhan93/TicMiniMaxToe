#ifndef MINI_INCLUDED
#define MINI_INCLUDED
#include "board.h"
#include "engine.h"
#include "players.h"
#include "move.h"

class MiniMax
{
	private:
		Board* board;
		Engine* engine;

		int min_search();
		int max_search();
	public:
		MiniMax() {};
		MiniMax(Board* board, Engine* engine);
		Move get_move();

};

#endif

