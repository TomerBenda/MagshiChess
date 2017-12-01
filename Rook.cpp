#include "Rook.h"

Rook::Rook(Position pos, char type, Board board) : Piece(pos, type, board)
{
}

Rook::~Rook()
{
}

bool Rook::checkMove(const Position& pos) const
{
	return pos.getLetter() == _index.getLetter() || pos.getNumber() == _index.getNumber();
}