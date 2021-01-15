#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

#include <vector>
#include <memory>
#include "..\utils\players.h"


class Board
{
	private:
		std::vector<std::vector<PlayerType>> board;


		Board() {};
		Board(int size);
	public:
		static std::shared_ptr<Board> get_board() ;
		static std::shared_ptr<Board> get_board(size_t size);

		size_t getSize();
		PlayerType getTile(int row,int col) const;
		void setTile(int row,int col,PlayerType value);

};

#endif
