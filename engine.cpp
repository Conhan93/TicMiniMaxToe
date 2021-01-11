#include "engine.h"
#include <algorithm>

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
bool Engine::check_win(PlayerType player)
{
	this->player = player;
	return horizontal_check(player) || vertical_check(player) || diagonal_check(player);
}
int Engine::get_player()
{
	return this->turn % 2 ? 1 : -1;
}
bool Engine::horizontal_check(PlayerType player)
{
	bool check{ true };
	// horizontal check
	for (auto row{ 0 }; row < this->board->getSize(); row++)
	{
		for (auto col{ 0 }; col < this->board->getSize(); col++)
		{
			check &= (board->getTile(row, col) == (int)player);
		}
		if (check) return true;
		else check = false;
	}
	return check;
}
bool Engine::vertical_check(PlayerType player)
{
	// vertical check
	bool check{ true };

	for (auto col{ 0 }; col < this->board->getSize(); col++)
	{
		for (auto row{ 0 }; row < this->board->getSize(); row++)
		{
			check &= board->getTile(row, col) == (int)player;
		}
		if (check) return true;
		else check = false;
	}
	return check;
}
bool Engine::diagonal_check(PlayerType player)
{
	// diag check
	bool check{ true };

	for (auto row{ 0 }; row < this->board->getSize(); row++)
	{
		check &= this->board->getTile(row, row) == (int)player;

	}
	return check;
}

bool Engine::is_tie()
{
	bool tie{ true };

	for (auto row{ 0 }; row < this->board->getSize(); row++)
	{
		for (auto col{ 0 }; col < this->board->getSize(); col++)
			if (this->board->getTile(row, col) == (int)PlayerType::EMPTY)
				tie = false;
	}

	return tie;
}
