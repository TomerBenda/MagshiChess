#pragma once
#include "Piece.h"
#include "Rook.h"

#include <string>
#include <vector>
#include <iostream>

class Piece;
class Board
{
public:
	Board(const std::string& matrixStr);
	~Board();

	void printState() const;
	void move(const Position& src, const Position& dst);
	void createPieces();
	std::string getMatrixStr() const;
	char getPiece(const Position& pos) const;

private:
	std::vector<Piece*> _pieces;
	std::string _matrixStr;
};
