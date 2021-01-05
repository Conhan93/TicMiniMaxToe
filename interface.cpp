#include "iostream"
#include "algorithm"
#include "interface.h"
#include "board.h"

Interface::Interface(TicTacToe* game)
{ 
	this->board = &game->board;
	this->engine = &game->engine;
}

void Interface::display_board(Board board) const
{
	for (auto row = 0; row < board.getSize(); row++)
	{
		for (auto col = 0; col < board.getSize(); col++)
		{
			if (!(col % board.getSize()))
				std::cout << "|" << std::endl;
			std::cout << "|" << board.getTile(row, col);
		}
			
	}
		

	/*
	auto print_row = [](std::vector<int> row) {
		for (auto col : row)
			std::cout << col << "|"; };

	std::for_each(board.begin(), board.end(), print_row);
	
	for (auto row : board)
		for (auto col : row)
			std::cout << col << "|";
	*/
}
bool Interface::make_move(int turn)
{
	int row, col;
	std::cout << "Enter row, col";
	std::cin >> row >> col;

	if (!board->getTile(row, col))
	{
		board->setTile(row, col, (turn % 2 ? 1 : -1));
		return true;
	}
	
	return false;
}