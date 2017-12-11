#include "Queen.h"

Queen::Queen(Position pos, char type, Board* board) : Piece(pos, type, board)
{
}

Queen::~Queen()
{
}

bool Queen::checkMove(const Position& pos) const
{
	// A queen can move the same way as both a Rook and a Bishop
	Bishop b(_index, isWhite() ? 'B' : 'b', _board);
	Rook r(_index, isWhite() ? 'R' : 'r', _board);
	return r.checkMove(pos) || b.checkMove(pos);
}
