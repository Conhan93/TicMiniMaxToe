#ifndef GAME_INCLUDED
#define GAME_INCLUDED
#include "board.h"
#include "interface.h"
#include "engine.h"
#include "MiniMax.h"

class TicTacToe
{
	
	private:
		
		
	public:
		MiniMax AI;
		Board board;
		Interface UI;
		Engine engine;

		TicTacToe(int size);
		void start();
};

#endif

