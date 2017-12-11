#pragma once
#include "Piece.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"

#include <string>
#include <iostream>
#include "Player.h"

class Piece;
class Player;

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
	Piece* operator[](Position pos) const;
	Player* getPlayer(bool player) const;
	void updateMatrixStr(int oldIndex, int newIndex);
	Piece* getPiece(const Position& src);
	void changePiece(Piece* newPiece, const Position& pos);
	void promote(Piece* promotion, const Position& old);

private:
	Piece* _pieces[SIDE_LEN][SIDE_LEN];
	std::string _matrixStr;
	Player* _white;
	Player* _black;
};

