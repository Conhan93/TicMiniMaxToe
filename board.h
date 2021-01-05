#pragma once

#include <vector>


class Board
{
	private:
		std::vector<std::vector<int>> board;
	public:
		Board() {};
		Board(size_t size);
		size_t getSize();
		int& getTile(int row, int col);
		void setTile(int row, int col, int value);

};

