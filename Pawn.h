#pragma once
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
	Pawn(Position pos, char type, Board* board);
	~Pawn();
	bool checkMove(const Position& pos) const;
	bool isAtStartPosition() const;
};

