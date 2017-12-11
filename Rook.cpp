#include "Rook.h"

Rook::Rook(Position pos, char type, Board* board) : Piece(pos, type, board)
{
}

Rook::~Rook()
{
}

bool Rook::checkMove(const Position& pos) const
{
	int moveBy;
	if (pos.getNumber() == _index.getNumber())
	{
		if (pos.getLetter() < _index.getLetter())
			moveBy = -1;
		else
			moveBy = 1;

		for (unsigned int i = _index.getIntLetter() + moveBy; i != pos.getIntLetter(); i += moveBy)
		{
			Position curr('a' + i, _index.getNumber() + 1);
			if ((*_board)[curr] != nullptr && !(curr == pos))
				return false;
		}
		return true;
	}
	else if (pos.getLetter() == _index.getLetter())
	{
		if (_index.getNumber() < pos.getNumber())
			moveBy = 1;
		else
			moveBy = -1;

		for (unsigned int i = _index.getNumber() + moveBy; i != pos.getNumber(); i += moveBy)
		{
			Position curr(_index.getLetter(), i + 1);
			if ((*_board)[curr] != nullptr && !(curr==pos))
				return false;
		}
		return true;
	}
	// If the destination is not in the same columm or row, it is an illegal move
	else
		return false;
}