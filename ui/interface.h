#ifndef INTERFACE_INCLUDED
#define INTERFACE_INCLUDED


#include <memory>
#include "..\board\board.h"
#include "..\engine\engine.h"
#include "..\utils\move.h"



class Interface
{
	private:
		std::shared_ptr<Board> board;
		Engine* engine;

		char format_tile(int row, int col) const;
	public:
		Interface() {};
		Interface(Engine* engine);

		void display_board() const;
		Move get_move();
};

#endif
