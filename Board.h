#pragma once
#include "Piece.h"
#include "Rook.h"
#include "King.h"
/*
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
*/
#include <string>
#include <iostream>

class Piece;
class King;

class Board
{
public:
	Board(const std::string& matrixStr);
	~Board();

	void printState() const;
	void move(const Position& src, const Position& dst);
	void createPieces();
	std::string getMatrixStr() const;
	Piece* operator[](int index) const;

private:
	Piece* _pieces[SIDE_LEN][SIDE_LEN];
	std::string _matrixStr;

	King* _kingW;
	King* _kingB;
};

