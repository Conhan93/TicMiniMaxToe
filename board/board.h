#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

#include <vector>
#include "..\utils\players.h"


class Board
{
	private:
		std::vector<std::vector<PlayerType>> board;


		Board() {};
		Board(size_t size);
	public:
		static Board* get_board();
		static Board* get_board(size_t size);

		size_t getSize();
		PlayerType getTile(int row, int col);
		void setTile(int row, int col, PlayerType value);

};

#endif
