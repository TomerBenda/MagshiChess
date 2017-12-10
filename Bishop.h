#pragma once
#include "Piece.h"
#include "Board.h"
#include <cmath>
class Bishop: public Piece
{
public:
	Bishop(Position pos, char type, Board* board);
	~Bishop();
	bool checkMove(const Position& pos) const;

};

