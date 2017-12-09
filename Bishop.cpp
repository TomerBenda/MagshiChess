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
	if (std::abs(_index.getLetter() - pos.getLetter()) == std::abs(_index.getNumber() - pos.getNumber()))
	{
		// If the bishop moves left and down
		if (_index.getLetter() > pos.getLetter())
			colMove = -1;
		else
			colMove = 1;
		if (_index.getNumber() > pos.getNumber())
			rowMove = -1;
		else
			rowMove = 1;

		for (int i = 1; i < std::abs(_index.getLetter() - pos.getLetter()); i++)
		{
			Position curr(_index.getLetter() + colMove*i, _index.getNumber() + rowMove*i);
			if ((*_board)[curr.translate()] != nullptr && !(curr == pos))
				return false;
		}
		return true;
	}
	return false;
}

