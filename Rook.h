#pragma once
#include "Piece.h"
#include "Board.h"

class Rook: public Piece
{
public:
	Rook(Position pos, char type, Board* board);
	~Rook();

	bool checkMove(const Position& pos) const;
	//true  == code 0
	//false == code 6
};

