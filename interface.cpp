#include "iostream"
#include "algorithm"
#include "interface.h"
#include "board.h"

Interface::Interface(Board* board, Engine* engine)
{ 
	this->board = board;
	this->engine = engine;
}

void Interface::display_board() const
{
	for (auto row = 0; row < this->board->getSize(); row++)
	{
		for (auto col = 0; col < this->board->getSize(); col++)
		{
			if (!(col % this->board->getSize()))
				std::cout << "|" << std::endl;
			std::cout << "|" << (int)this->board->getTile(row, col);
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
bool Interface::make_move()
{
	int row, col;
	std::cout << "\nEnter row:";
	std::cin >> row;
	std::cout << "\nEnter col:";
	std::cin >> col;

	if (!(int)board->getTile(row, col))
	{
		board->setTile(row, col, this->engine->get_player());
		return true;
	}
	
	return false;
}