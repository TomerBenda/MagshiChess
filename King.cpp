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

bool King::checkCheck(Position pos) const
{
	for (int i = 1; i <= SIDE_LEN; i++)
	{
		for (int j = 0; j < SIDE_LEN; j++)
		{
			Position currPos('a' + j, i);
			Piece* curr = (*_board)[currPos];
			// Checking if there exists a piece at the current index, which is not the King itself, and can move to the king's location.
			if (curr && isEnemy(*curr) && !(pos==currPos) && curr->checkMove(_index))
				return true;
		}
	}
	return false;
}