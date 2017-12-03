#pragma once
#include "Piece.h"

class King: public Piece
{
public:
	King(Position pos, char type, Board* board);
	~King();
	bool checkMove(const Position& pos) const;
};

