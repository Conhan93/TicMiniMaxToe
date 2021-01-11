#ifndef INTERFACE_INCLUDED
#define INTERFACE_INCLUDED

#include "board.h"
#include "engine.h"



class Interface
{
	private:
		Board* board;
		Engine* engine;
	public:
		Interface() {};
		Interface(Board* board, Engine* engine);

		void display_board() const;
		bool make_move();
};

#endif
