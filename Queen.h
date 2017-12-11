#pragma once
#include "Piece.h"
#include "Board.h"

class Queen : public Piece
{
public:
	Queen(Position pos, char type, Board* board);
	~Queen();
	bool checkMove(const Position& pos) const;
};

