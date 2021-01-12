#include "engine.h"
#include <algorithm>

Engine::Engine(Board* board)
{
	this->board = board;
	this->turn = 1;
	this->player = PlayerType::HUMAN;
}
void Engine::next_turn()
{
	this->turn++;
	this->player = static_cast<PlayerType>((int)player * -1);
}
int Engine::get_turn()
{
	return this->turn;
}
bool Engine::make_move(int row, int col)
{
	if (valid_move(row, col))
	{
		this->board->setTile(row, col, get_player());
		return true;
	}
	return false;
}
bool Engine::valid_move(int row, int col)
{
	return this->board->getTile(row, col) == PlayerType::EMPTY;
}
bool Engine::check_win(PlayerType player)
{
	//this->player = player;
	return horizontal_check(player) || vertical_check(player) || diagonal_check(player);
}
PlayerType Engine::get_player()
{
	return this->player;
	//return this->turn % 2 ? 1 : -1;
}
bool Engine::horizontal_check(PlayerType player)
{
	bool check{ true };
	// horizontal check
	for (auto row{ 0 }; row < this->board->getSize(); row++)
	{
		for (auto col{ 0 }; col < this->board->getSize(); col++)
		{
			check &= (board->getTile(row, col) == player);
		}
		if (check) return true;
		check = true;
	}
	return false;
}
bool Engine::vertical_check(PlayerType player)
{
	// vertical check
	bool check{ true };

	for (auto col{ 0 }; col < this->board->getSize(); col++)
	{
		for (auto row{ 0 }; row < this->board->getSize(); row++)
		{
			check &= board->getTile(row, col) == player;
		}
		if (check) return true;
		check = true;
	}
	return false;
}
bool Engine::diagonal_check(PlayerType player)
{
	// diag check
	bool check{ true };

	for (auto row{ 0 }; row < this->board->getSize(); row++)
	{
		check &= this->board->getTile(row, row) == player;

	}
	if (check) return true;
	check = true;
	for (auto col{ 0 }; col < this->board->getSize(); col++)
	{
		check &= this->board->getTile(this->board->getSize() - (col + 1), col) == player;

	}
	if (check) return true;

	return false;
}

bool Engine::is_tie()
{
	bool tie{ true };

	for (auto row{ 0 }; row < this->board->getSize(); row++)
		for (auto col{ 0 }; col < this->board->getSize(); col++)
			if (this->board->getTile(row, col) == PlayerType::EMPTY)
				tie = false;

	return tie;
}
