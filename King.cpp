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