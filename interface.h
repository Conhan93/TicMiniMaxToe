#include "board.h"


class Interface
{
	private:
		Board* board;
	public:
		Interface(Board* board);
		void display_board(Board board) const;
		bool make_move(int turn);
};