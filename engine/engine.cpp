#include "engine.h"

//Board* board
Engine::Engine()
{
	this->board = Board::get_board();
	this->player = PlayerType::HUMAN;
}
void Engine::next_turn()
{
	this->player = static_cast<PlayerType>((int)player * -1);
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
bool Engine::valid_move(int row, int col) const
{
	return this->board->getTile(row, col) == PlayerType::EMPTY;
}
bool Engine::check_win(PlayerType player) const
{
	return horizontal_check(player) || vertical_check(player) || diagonal_check(player);
}
PlayerType Engine::get_player()
{
	return this->player;
}
bool Engine::horizontal_check(PlayerType player) const
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
bool Engine::vertical_check(PlayerType player) const
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
bool Engine::diagonal_check(PlayerType player) const
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

bool Engine::is_tie() const
{
	bool tie{ true };

	for (auto row{ 0 }; row < this->board->getSize(); row++)
		for (auto col{ 0 }; col < this->board->getSize(); col++)
			if (this->board->getTile(row, col) == PlayerType::EMPTY)
				tie = false;

	return tie;
}
