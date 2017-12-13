#include "Bishop.h"



Bishop::Bishop(Position pos, char type, Board* board) : Piece(pos, type, board)
{
}

Bishop::~Bishop()
{
}

bool Bishop::checkMove(const Position& pos) const
{
	int colMove, rowMove;
	int letterDiff = _index.getLetter() - pos.getLetter();
	int numDiff = _index.getNumber() - pos.getNumber();
	if (std::abs(letterDiff) == std::abs(numDiff))
	{
		// Checking which direction the bishop moves to
		letterDiff > 0 ? colMove = -1 : colMove = 1;
		numDiff > 0 ? rowMove = -1 : rowMove = 1;

		for (int i = 1; i < std::abs(letterDiff); i++)
		{
			Position curr(_index.getLetter() + colMove*i, _index.getNumber() + 1 + rowMove*i);
			if ((*_board)[curr] != nullptr && !(curr == pos))
				return false;
		}
		return true;
	}
	return false;
}

