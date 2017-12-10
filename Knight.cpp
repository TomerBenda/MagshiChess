#include "Knight.h"

Knight::Knight(Position pos, char type, Board* board) : Piece(pos, type, board)
{
}

Knight::~Knight()
{
}

bool Knight::checkMove(const Position& pos) const
{
	int numDiff = _index.getNumber() - pos.getNumber();
	int letDiff = _index.getLetter() - pos.getLetter();

	return (abs(numDiff) == 2 && abs(letDiff) == 1)
		|| (abs(numDiff) == 1 && abs(letDiff) == 2);
}