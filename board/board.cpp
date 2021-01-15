#include "board.h"

std::shared_ptr<Board> board_instance = nullptr;


Board::Board(int size)
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

std::shared_ptr<Board> Board::get_board()
{
	return board_instance;
}

std::shared_ptr<Board> Board::get_board(size_t size)
{
	if(!board_instance)
		board_instance.reset(new Board(size));
	return board_instance;
}
