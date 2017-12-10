#pragma once
#include "Piece.h"
#include "Board.h"

class Knight : public Piece
{
public:
	Knight(Position pos, char type, Board* board);
	~Knight();
	bool checkMove(const Position& pos) const;
};

