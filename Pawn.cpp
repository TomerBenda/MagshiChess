#include "Pawn.h"

Pawn::Pawn(Position pos, char type, Board* board) : Piece(pos, type, board)
{
}

Pawn::~Pawn()
{
}

bool Pawn::checkMove(const Position& pos) const
{
	int numDiff = _index.getNumber() - pos.getNumber();
	int letDiff = _index.getLetter() - pos.getLetter();

	int colorDirection = isWhite() ? -1 : 1;

	//on the first turn, the pawn gets a double step
	bool isValidBigInitMove = (numDiff == 2 * (colorDirection) &&
		letDiff == 0 &&
		(*_board)[pos] == nullptr &&
		isAtStartPosition());

	//the pawn can "eat" an enemy's piece if it's on a one-step diagonal (bonus)
	bool isValidDiagonalMove = (numDiff == 1 * (colorDirection) &&
		abs(letDiff) == 1 &&
		(*_board)[pos] != nullptr &&
		isEnemy(*(*_board)[pos]));

	//normal one-step
	bool isValidSmallMove = (numDiff == 1 * (colorDirection) &&
		letDiff == 0 &&
		(*_board)[pos] == nullptr);


	bool isValidMove = isValidSmallMove || isValidDiagonalMove || isValidBigInitMove;

	//if the pawn reaches the other side of the board, it is promoted(bonus)
	bool isPromotion = (isValidMove &&
		pos.getNumber() == (SIDE_LEN - 1) * isWhite() + 1);
	if (isPromotion)
	{
		Piece* promotion = new Queen(pos, isWhite() ? 'Q' : 'q', _board);
		(*_board).promote(promotion, _index);
		(*_board).printState();
	}

	return isValidMove;
}

bool Pawn::isAtStartPosition() const{
	return (isWhite() && _index.getNumber() == 2) 
		|| (!isWhite() && _index.getNumber() == 7);
}