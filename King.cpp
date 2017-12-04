#include "King.h"

King::King(Position pos, char type, Board* board) : Piece(pos, type, board)
{
}


King::~King()
{
}
	
bool King::checkMove(const Position& pos) const
{
	return (abs(_index.getLetter() - pos.getLetter()) <= 1) && (abs(_index.getNumber() - pos.getNumber()) <= 1);
}

bool King::checkCheck() const
{
	for (int i = 0; i < SIDE_LEN; i++)
	{
		for (int j = 0; j < SIDE_LEN; j++)
		{
			Position a(i, j);
			Piece* curr = (*_board)[a.translate()];
			if (curr && curr->getType() != _type && curr->checkMove(_index))
				return true;
		}
	}
	return false;
}