#ifndef GAME_INCLUDED
#define GAME_INCLUDED
#include "board\board.h"
#include "ui\interface.h"
#include "engine\engine.h"
#include "AI\MiniMax.h"
#include <memory>

class TicTacToe
{

	private:


	public:
		AI* computer;
		std::shared_ptr<Board> board;
		Interface UI;
		Engine engine;

		TicTacToe(int size);
		void start();
};

#endif
