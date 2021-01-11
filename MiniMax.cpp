#include "MiniMax.h"
#include "players.h"
#include <numeric>





Move MiniMax::get_move()
{
	int score = std::numeric_limits<int>::min(), temp_score;
	Move move;

	for (int row = 0; row < this->board->getSize(); row++)
	{
		for (int col = 0; col < this->board->getSize(); col++)
		{
			if (this->board->getTile(row, col) == (int)PlayerType::EMPTY)
			{
				this->board->setTile(row, col, (int)PlayerType::COMPUTER);
				if ((temp_score = max_search()) > score)
				{
					score = temp_score;
					move.row = row;
					move.col = col;

				}
				this->board->setTile(row, col, (int)PlayerType::EMPTY);
				
			}
		}
	}
	return move;
}
int MiniMax::min_search()
{
	int score = std::numeric_limits<int>::min();
	if (this->engine->check_win(PlayerType::COMPUTER)) return 10;
	else if (this->engine->check_win(PlayerType::HUMAN)) return -10;
	else if (this->engine->is_tie()) return 0;

	for (int row = 0; row < this->board->getSize(); row++)
	{
		for (int col = 0; col < this->board->getSize(); col++)
		{
			if (this->board->getTile(row, col) == (int)PlayerType::EMPTY)
			{
				this->board->setTile(row, col, (int)PlayerType::COMPUTER);
				score = std::max(score, max_search());
				this->board->setTile(row, col, (int)PlayerType::EMPTY);

			}
		}
	}
	return score;
}
int MiniMax::max_search()
{
	int score = std::numeric_limits<int>::max();
	if (this->engine->check_win(PlayerType::COMPUTER)) return 10;
	else if (this->engine->check_win(PlayerType::HUMAN)) return -10;
	else if (this->engine->is_tie()) return 0;

	for (int row = 0; row < this->board->getSize(); row++)
	{
		for (int col = 0; col < this->board->getSize(); col++)
		{
			if (this->board->getTile(row, col) == (int)PlayerType::EMPTY)
			{
				this->board->setTile(row, col, (int)PlayerType::HUMAN);
				score = std::min(score, min_search());
				this->board->setTile(row, col, (int)PlayerType::EMPTY);

			}
		}
	}
	return score;

}
MiniMax::MiniMax(Board* board, Engine* engine)
{
	this->board = board;
	this->engine = engine;
}
