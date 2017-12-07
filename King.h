#pragma once
#include "Board.h"
#include "Piece.h"

class Board;

class King: public Piece
{
public:
	King(Position pos, char type, Board* board);
	~King();
	bool checkMove(const Position& pos) const;
};

