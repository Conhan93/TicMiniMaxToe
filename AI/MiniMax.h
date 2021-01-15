#ifndef MINI_INCLUDED
#define MINI_INCLUDED

#include "ai.h"
#include "..\board\board.h"
#include "..\engine\engine.h"
#include "..\utils\players.h"
#include "..\utils\move.h"

class MiniMax : public AI
{
	private:

		enum Evaluation
		{
			GAME_NOT_FINISHED = -1,
			COMPUTER_WIN = 10,
			HUMAN_WIN = -10,
			TIE = 0,
		};

		std::shared_ptr<Board> board;
		Engine* engine;
		int board_size;

		int min_search();
		int max_search();
		int evaluate_board();
	public:
		MiniMax() {};
		MiniMax(Engine* engine);
		Move get_move() override;

};

#endif
