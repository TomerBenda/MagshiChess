#include "gameManager.h"
const int PLAYER_INDEX = 64;

gameManager::gameManager(const std::string& str) : _board(str.substr(0, 64)), _curr(str[PLAYER_INDEX] == 0)
{
}

gameManager::~gameManager()
{
}

std::string gameManager::boardState()
{
	return _board.getMatrixStr();
}
int gameManager::makeTurn(std::string move)
{
	Position* src;
	Position* dst;
	// Checking if the 2 positions exist on the board
	try
	{
		src = new Position(move[0], move[1] - '0');
		dst = new Position(move[2], move[3] - '0');
	}
	catch (std::invalid_argument invalid_index)
	{
		return 5;
	}

	if (src == dst)
		return 7;

	Piece* toMove = _board[src->translate()];
	Player* currentPlayer = _board.getPlayer(_curr);
	Player* opponentPlayer = _board.getPlayer(!_curr);

	// Checking if the source position is null or has a piece that belongs to the current player.
	if (toMove == nullptr || _curr !=  toMove->isWhite())
		return 2;
	// Checking if the destination has piece, which belongs to the current player.
	if (_board[dst->translate()] != nullptr && !(toMove->isEnemy(*_board[dst->translate()])))
		return 3;

	// First, if the king is the piece to be moved - It cannot move to a location that will cause Check on itself.
	if (tolower(toMove->getType()) == 'k')
	{
		bool checkResult = currentPlayer->getKing()->checkCheck(*dst);
		// The king cannot cause Check on the other king, since it would put him in attack range from the opponent's king.
		if (!toMove->checkMove(*dst))
			return 6;
		// If the move does not cause Check, this means the king is not threatened.
		if (!checkResult)
		{
			currentPlayer->setThreatened(false);
			_board.move(*src, *dst);
		}
		else
			return 6;
	}
	else
	{
		if (!(toMove->checkMove(*dst)))
			return 6;

		// The move is legal, now checking if the piece to move causes Check on the opponent's king
		_board.move(*src, *dst);
		if (!(opponentPlayer->getThreatened()) && opponentPlayer->getKing()->checkCheck(opponentPlayer->getKing()->getPos()))
		{
			opponentPlayer->setThreatened(true);
			toggleCurrPlayer(); // The function will return 1, meaning the turn was legal.
			return 1;
		}	
	}
	// If the code reached this point, the move is legal and does not cause Check.
	toggleCurrPlayer();
	return 0;
}
void gameManager::toggleCurrPlayer()
{
	_curr = !_curr;
}

void gameManager::printState()
{
	_board.printState();
}