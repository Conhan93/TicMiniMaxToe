#include "board.h"

Board* board_instance = nullptr;


Board::Board(size_t size)
{
	this->board.resize(size);

	for (auto row = 0; row < size; row++)
		this->board[row].resize(size);
}
size_t Board::getSize() { return this -> board.size(); }
PlayerType Board::getTile(int row,int col) const
{
	return this->board[row][col];
}
void Board::setTile(int row, int col, PlayerType value)
{
	this->board[row][col] = value;
}

Board* Board::get_board()
{
	return board_instance;
}

Board* Board::get_board(size_t size)
{
	if(!board_instance)
		board_instance = new Board(size);
	return board_instance;
}
