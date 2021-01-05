#include "engine.h"


Engine::Engine(Board* board)
{
	this->board = board;
	this->turn = 1;
}
void Engine::next_turn()
{
	this->turn++;
}
int Engine::get_turn()
{
	return this->turn;
}
bool Engine::make_move(int row, int col)
{
	if (!this->board->getTile(row, col))
	{
		this->board->setTile(row, col, get_player());
		return true;
	}
	return false;
}
bool Engine::check_win()
{
	bool check{ true };
	// horizontal check
	for (auto row{ 0 }; row < this->board->getSize(); row++)
	{
		for (auto col{ 0 }; col < this->board->getSize(); col++)
		{
			check &= board->getTile(row, col) == get_player();
		}
		if (check) return true;
	}
	return false;
	// vertical check
	for (auto col{ 0 }; col < this->board->getSize(); col++)
	{
		for (auto row{ 0 }; row < this->board->getSize(); row++)
		{
			check &= board->getTile(row, col) == get_player();
		}
		if (check) return true;
	}
	return false;
	// diag check
	for (auto row{ 0 }; row < this->board->getSize(); row++)
	{
		check &= this->board->getTile(row, row) == get_player();
	}
	return check;
}
int Engine::get_player()
{
	return this->turn % 2 ? 1 : -1;
}