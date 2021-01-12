#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

#include <vector>
#include "players.h"


class Board
{
	private:
		std::vector<std::vector<PlayerType>> board;
	public:
		Board() {};
		Board(size_t size);
		size_t getSize();
		PlayerType getTile(int row, int col);
		void setTile(int row, int col, PlayerType value);

};

#endif

