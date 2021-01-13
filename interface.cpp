#include <iostream>
#include <iomanip>
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
	std::cout << std::right << std::setw(2) << std::endl;
	for (auto row = 0; row < this->board->getSize(); row++)
	{
		std::cout << "  ";
		for (auto col = 0; col < this->board->getSize(); col++)
		{
			std::cout << "|" << display_tile(row, col);
		}
		std::cout << "|" << std::endl;
			
	}
	std::cout << std::endl << std::endl;
}
char Interface::display_tile(int row, int col) const
{
	PlayerType tile = this->board->getTile(row, col);
	switch (tile)
	{
	case PlayerType::EMPTY:
		return ' ';
	case PlayerType::HUMAN:
		return 'X';
	case PlayerType::COMPUTER:
		return 'O';
	default:
		break;
	}
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