#include "Piece.h"

Piece::Piece(Position pos, char type, Board* board) : _index(pos), _type(type), _board(board)
{
}
Piece::~Piece()
{
}

Position Piece::getPos() const
{
	return _index;
}
bool Piece::isWhite() const
{
	return 'A' < _type && _type < 'Z';
}
char Piece::getType() const
{
	return _type;
}
bool Piece::isEnemy(const Piece& other) const
{
	return isWhite() != other.isWhite();
}
void Piece::move(const Position& pos)
{
	_index = pos;
}

