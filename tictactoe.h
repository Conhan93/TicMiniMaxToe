#pragma once
#include "board.h"
#include "interface.h"
#include "engine.h"

class TicTacToe
{
	private:
		
		
	public:
		Board board;
		Interface UI;
		Engine engine;

		TicTacToe(int size);
		void start();
};

