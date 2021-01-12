#include "MiniMax.h"
#include "players.h"
#include <numeric>





Move MiniMax::get_move()
{
	int score = std::numeric_limits<int>::min(), temp_score;
	Move move;

	for (int row = 0; row < this->board_size; row++)
	{
		for (int col = 0; col < this->board_size; col++)
		{
			if (this->board->getTile(row, col) == PlayerType::EMPTY)
			{
				this->board->setTile(row, col, PlayerType::COMPUTER);
				if ((temp_score = max_search()) > score)
				{
					score = temp_score;
					move.row = row;
					move.col = col;

				}
				this->board->setTile(row, col, PlayerType::EMPTY);
				
			}
		}
	}
	return move;
}
int MiniMax::min_search()
{
	int score = std::numeric_limits<int>::min(), board_value;
	if ((board_value = evaluate_board()) != GAME_NOT_FINISHED) return board_value; // error


	for (int row = 0; row < this->board_size; row++)
	{
		for (int col = 0; col < this->board_size; col++)
		{
			if (this->board->getTile(row, col) == PlayerType::EMPTY)
			{
				this->board->setTile(row, col, PlayerType::COMPUTER);
				score = std::max(score, max_search());
				this->board->setTile(row, col, PlayerType::EMPTY);

			}
		}
	}
	return score;
}
int MiniMax::max_search()
{
	int score = std::numeric_limits<int>::max(), board_value;
	if ((board_value = evaluate_board())  != GAME_NOT_FINISHED) return board_value;

	for (int row = 0; row < this->board_size; row++)
	{
		for (int col = 0; col < this->board_size; col++)
		{
			if (this->board->getTile(row, col) == PlayerType::EMPTY)
			{
				this->board->setTile(row, col, PlayerType::HUMAN);
				score = std::min(score, min_search());
				this->board->setTile(row, col, PlayerType::EMPTY);

			}
		}
	}
	return score;

}
int MiniMax::evaluate_board()
{
	if (this->engine->check_win(PlayerType::COMPUTER)) return COMPUTER_WIN;
	else if (this->engine->check_win(PlayerType::HUMAN)) return HUMAN_WIN;
	else if (this->engine->is_tie()) return TIE;
	else return GAME_NOT_FINISHED;
}
MiniMax::MiniMax(Board* board, Engine* engine)
{
	this->board = board;
	this->engine = engine;
	this->board_size = board->getSize();
}
