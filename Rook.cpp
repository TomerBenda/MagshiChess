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

		for (unsigned int i = _index.getLetter() - 'a' + moveBy; i != pos.getLetter() - 'a'; i += moveBy)
		{
			Position curr('a' + i, _index.getNumber());
			if ((*_board)[curr.translate()] != nullptr && !(curr == pos))
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
			Position curr(_index.getLetter(), i);
			if ((*_board)[curr.translate()] != nullptr && !(curr==pos))
				return false;
		}
		return true;
	}
	// If the destination is not in the same columm or row, it is an illegal move
	else
		return false;
}