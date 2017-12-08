#pragma once
#include "Position.h"
//#include "Board.h"

class Board;

class Piece
{
public:
	Piece(Position pos, char type, Board* board);
	virtual ~Piece();
	virtual bool checkMove(const Position& pos) const = 0;
	Position getPos() const;
	bool isWhite() const;
	char getType() const;
	bool isEnemy(const Piece& other) const;
	void move(const Position& pos);

protected:
	Position _index;
	Board* _board;
	char _type;
};

