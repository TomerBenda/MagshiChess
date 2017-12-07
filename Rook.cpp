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
			if ((*_board)[Position('a' + i, _index.getNumber()).translate()] != nullptr)
				return false;
		return true;
	}
	else if (pos.getLetter() == _index.getLetter())
	{
		if (_index.getNumber() < pos.getNumber())
			moveBy = 1;
		else
			moveBy = -1;

		for (unsigned int i = _index.getNumber() + moveBy; i != pos.getNumber() - 1; i += moveBy)
			if ((*_board)[Position(_index.getLetter(), i).translate()] != nullptr)
				return false;
		return true;
	}
	else
		return false;
}