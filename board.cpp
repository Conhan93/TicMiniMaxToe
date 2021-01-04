#include "board.h"



Board::Board(size_t size)
{
	this->board.resize(size);

	for (auto row = 0; row < size; row++)
		this->board[row].resize(size);


}
size_t Board::getSize() { return this -> board.size(); }
int& Board::getTile(int row, int col)
{
	return this->board[row][col];
}
void Board::setTile(int row, int col, int value)
{
	this->board[row][col] = value;
}