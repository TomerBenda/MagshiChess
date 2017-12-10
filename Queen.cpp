#include "Queen.h"

Queen::Queen(Position pos, char type, Board* board) : Piece(pos, type, board)
{
}

Queen::~Queen()
{
}

bool Queen::checkMove(const Position& pos) const
{
	int numDiff = _index.getNumber() - pos.getNumber();
	int letDiff = _index.getLetter() - pos.getLetter();
	
	//check if the move is legal in any direction
	bool isDiagonalMove = abs(numDiff) == abs(letDiff)
		&& numDiff != 0 && letDiff != 0;

	bool isVerticalMove = abs(numDiff) > 0 && abs(letDiff) == 0;
	bool isHorizontalMove = abs(numDiff) == 0 && abs(letDiff) > 0;

	
	if (!isVerticalMove && !isHorizontalMove && !isDiagonalMove)
		return false;

	//determine the exact direction of the movement
	int numSign = 0;
	int letSign = 0;

	if (isVerticalMove) 
		numSign = numDiff < 0 ? 1 : -1;

	if (isHorizontalMove) 
		letSign = letDiff < 0 ? 1 : -1;

	if (isDiagonalMove)
	{
		numSign = numDiff < 0 ? 1 : -1;
		letSign = letDiff < 0 ? 1 : -1;
	}
	
	//start checking if move is valid
	int num = _index.getNumber() + numSign;
	int let = _index.getIntLetter() + letSign;
	
	bool wayIsEmpy = true;
	bool whileCondition = false;

	if (isVerticalMove) {
		whileCondition = num != pos.getNumber();
	}
	else if (isHorizontalMove) {
		whileCondition = let != pos.getIntLetter();
	}
	else if (isDiagonalMove) {
		whileCondition = num != pos.getNumber()
			&& let != pos.getIntLetter();
	}

	//check if there are pieces blocking the movement
	while (whileCondition) 
	{
		Position *tmpPos = new Position(let + 'a', num);

		if ((*_board)[*tmpPos] != nullptr) {
			wayIsEmpy = false;
			break;
		}
		else {
			delete tmpPos;
		}

		num += numSign;
		let += letSign;

		//calculate if the loop should continue
		if (isVerticalMove) {
			whileCondition = num != pos.getNumber();
		}
		else if (isHorizontalMove) {
			whileCondition = let != pos.getIntLetter();
		}
		else if (isDiagonalMove) {
			whileCondition = num != pos.getNumber()
				&& let != pos.getIntLetter();
		}
	}
	return wayIsEmpy;
}